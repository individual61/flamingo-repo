#include <parameters.h>
#include <function_declarations_and_globals.h>

bool imu_active = 1;

float acc_x, acc_y, acc_z;
float acc_filt_x, acc_filt_y, acc_filt_z;

SimpleKalmanFilter acc_kalman_filter_x(ACC_KALMAN_MEASUREMENT_UNCERTAINTY, ACC_KALMAN_ESTIMATION_UNCERTAINTY, ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY);
SimpleKalmanFilter acc_kalman_filter_y(ACC_KALMAN_MEASUREMENT_UNCERTAINTY, ACC_KALMAN_ESTIMATION_UNCERTAINTY, ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY);
SimpleKalmanFilter acc_kalman_filter_z(ACC_KALMAN_MEASUREMENT_UNCERTAINTY, ACC_KALMAN_ESTIMATION_UNCERTAINTY, ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY);

uint8_t imu_initialize(void)
{
    if (IMU.begin())
    {
        acc_x = 0.0;
        acc_y = 0.0;
        acc_z = 0.0;
        acc_filt_x = 0.0;
        acc_filt_y = 0.0;
        acc_filt_z = 0.0;

#if SERIAL_OUT_ACC == 1
        Serial.print("Acc sample rate = ");
        Serial.print(IMU.accelerationSampleRate());
        Serial.println(" Hz");
#endif

        return 1;
    }
    else
    {
        return 0;
    }
}

void imu_update_accel_values_filtered(void)
{
    acc_filt_x = acc_kalman_filter_x.updateEstimate(acc_x);
    acc_filt_y = acc_kalman_filter_y.updateEstimate(acc_y);
    acc_filt_z = acc_kalman_filter_z.updateEstimate(acc_z);

#if SERIAL_OUT_ACC == 1
//    Serial.print("gx:");
    Serial.print(acc_x);
    Serial.print(",");
//    Serial.print("gy:");
    Serial.print(acc_y);
    Serial.print(",");
//    Serial.print("gx:");
    Serial.print(acc_z);
    Serial.print(",");
//    Serial.print("g_filt_x:");
    Serial.print(acc_filt_x);
    Serial.print(",");
 //   Serial.print("g_filt_y:");
    Serial.print(acc_filt_y);
    Serial.print(",");
//    Serial.print("g_filt_x:");
    Serial.println(acc_filt_z);
#endif
}

void imu_update_accel_values(void)
{

    if (IMU.accelerationAvailable())
    {
        IMU.readAcceleration(acc_x, acc_y, acc_z);
        imu_update_accel_values_filtered();
    }
}

// SimpleKalmanFilter(e_mea, e_est, q);
// e_mea: Measurement Uncertainty
// e_est: Estimation Uncertainty
// q: Process Noise

// SERIAL_OUT_ACC
/*
#include <SimpleKalmanFilter.h>
#include <SFE_BMP180.h>


SimpleKalmanFilter pressureKalmanFilter(1, 1, 0.01);

SFE_BMP180 pressure;

// Serial output refresh time
const long SERIAL_REFRESH_TIME = 100;
long refresh_time;

float baseline; // baseline pressure

double getPressure()
{
    char status;
    double T, P;
    status = pressure.startTemperature();
    if (status != 0)
    {
        delay(status);
        status = pressure.getTemperature(T);
        if (status != 0)
        {
            status = pressure.startPressure(3);
            if (status != 0)
            {
                delay(status);
                status = pressure.getPressure(P, T);
                if (status != 0)
                {
                    return (P);
                }
            }
        }
    }
}

void setup()
{

    Serial.begin(115200);

    // BMP180 Pressure sensor start
    if (!pressure.begin())
    {
        Serial.println("BMP180 Pressure Sensor Error!");
        while (1)
            ; // Pause forever.
    }
    baseline = getPressure();
}

void loop()
{

    float p = getPressure();
    float altitude = pressure.altitude(p, baseline);
    float estimated_altitude = pressureKalmanFilter.updateEstimate(altitude);

    if (millis() > refresh_time)
    {
        Serial.print(altitude, 6);
        Serial.print(",");
        Serial.print(estimated_altitude, 6);
        Serial.println();
        refresh_time = millis() + SERIAL_REFRESH_TIME;
    }
}

*/