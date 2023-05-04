#include <parameters.h>
#include <function_declarations_and_globals.h>

bool imu_active = 1;

float acc_g_x, acc_g_y, acc_g_z;                  // global
float acc_g_filt_x, acc_g_filt_y, acc_g_filt_z;   // global

SimpleKalmanFilter acc_kalman_filter_x(ACC_KALMAN_MEASUREMENT_UNCERTAINTY, ACC_KALMAN_ESTIMATION_UNCERTAINTY, ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY);
SimpleKalmanFilter acc_kalman_filter_y(ACC_KALMAN_MEASUREMENT_UNCERTAINTY, ACC_KALMAN_ESTIMATION_UNCERTAINTY, ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY);
SimpleKalmanFilter acc_kalman_filter_z(ACC_KALMAN_MEASUREMENT_UNCERTAINTY, ACC_KALMAN_ESTIMATION_UNCERTAINTY, ACC_KALMAN_PROCESS_NOISE_UNCERTAINTY);

bool imu_initialize(void)
{
    if (IMU.begin())
    {
        acc_g_x = 0.0;
        acc_g_y = 0.0;
        acc_g_z = 0.0;
        acc_g_filt_x = 0.0;
        acc_g_filt_y = 0.0;
        acc_g_filt_z = 0.0;

        Serial.print("Acc sample rate = ");
        Serial.print(IMU.accelerationSampleRate());
        Serial.println(" Hz");

        return 1;
    }
    else
    {
        return 0;
    }
}

void imu_update_accel_values_filtered(void)
{
    acc_g_filt_x = acc_kalman_filter_x.updateEstimate(acc_g_x);
    acc_g_filt_y = acc_kalman_filter_y.updateEstimate(acc_g_y);
    acc_g_filt_z = acc_kalman_filter_z.updateEstimate(acc_g_z);

#if SERIAL_OUT_ACC_PLOT == 1
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
        IMU.readAcceleration(acc_g_x, acc_g_y, acc_g_z);
        acc_g_x = acc_g_x - 1.0;
        acc_g_y = acc_g_y - 1.0;
        acc_g_z = acc_g_z - 1.0;
        //imu_update_accel_values_filtered();
    }
}

float imu_get_update_rate(void)
{
    return IMU.accelerationSampleRate();
}