#include <parameters.h>
#include <function_declarations_and_globals.h>

// Same for both LSM9DS1/BMI270_BMM150
// Accelerometer range is set at [-4, +4]g -/+0.122 mg.
// Gyroscope range is set at [-2000, +2000] dps +/-70 mdps.
// Magnetometer range is set at [-400, +400] uT +/-0.014 uT.
// Accelerometer output data rate is fixed at 104 Hz.
// Gyroscope output data rate is fixed at 104 Hz.
// Magnetometer output data rate is fixed at 20 Hz.

bool imu_active = 1;
bool mag_active = 1;

float acc_g_x, acc_g_y, acc_g_z;                // global
float acc_g_filt_x, acc_g_filt_y, acc_g_filt_z; // global
float mag_g_x, mag_g_y, mag_g_z;                // global


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


//        Serial.print(time_interval_us);
//        Serial.print("\t");
//        Serial.println(acc_g_z);

        // imu_update_accel_values_filtered();
    }
}

float imu_get_update_rate(void)
{
    return IMU.accelerationSampleRate();
}



void mag_update_mag_values(void)
{

    if (IMU.magneticFieldAvailable())
    {

        IMU.readMagneticField(mag_g_x, mag_g_y, mag_g_z);
    }
}