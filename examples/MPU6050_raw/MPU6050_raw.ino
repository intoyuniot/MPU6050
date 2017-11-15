// 读取MPU6050三轴加速度值和三轴角速度值

#include <MPU6050.h>
//默认使用 SDA--  SCL--
MPU6050 mpu6050;

//加速度计的x y z的值
int16_t acc_x_temp,acc_y_temp,acc_z_temp;
//陀螺仪的x y z的值
int16_t gyro_x_temp,gyro_y_temp,gyro_z_temp;

void setup()
{
    Serial.begin(115200);
    //启动I2C
    Wire.begin();
    delay(500);
    mpu6050.begin();
    delay(100);
}

void loop()
{
    // 获取6轴数据，并输出
    mpu6050.getMotion6(&acc_x_temp, &acc_y_temp, &acc_z_temp, &gyro_x_temp, &gyro_y_temp, &gyro_z_temp);

    Serial.print("加速度-X:");
    Serial.print(acc_x_temp);
    Serial.print("\t");

    Serial.print("加速度-Y:");
    Serial.print(acc_y_temp);
    Serial.print("\t");

    Serial.print("加速度-Z:");
    Serial.print(acc_z_temp);
    Serial.print("\t");

    Serial.print("陀螺仪-X::");
    Serial.print(gyro_x_temp);
    Serial.print("\t");

    Serial.print("陀螺仪-Y:");
    Serial.print(gyro_y_temp);
    Serial.print("\t");

    Serial.print("陀螺仪-Z:");
    Serial.print(gyro_z_temp);
    Serial.print("\t");

    Serial.print("\r\n");
}
