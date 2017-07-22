#include "Exec06.h"

// グローバル変数
// DriveクラスのオブジェクトDriveを生成
Drive drive;

// モーターのピンを指定
int motor_L = 5;
int motor_R = 6;

// initialize for Arduino
void setup() {
  pinMode(motor_L, OUTPUT);
  pinMode(motor_R, OUTPUT);
  
  Serial.begin(9600);
}

// main loop
void loop() {
  // 各センサーの状態を保持する処理
  drive.Stored();

  // 左右のモーターの回転の初期値を設定
  drive.leftMotor->SetPower(250);
  drive.rightMotor->SetPower(250);

  // センサーの状態によって回転の速度を弱める
  for ( int i=0 ; i<3 ; i++ ){
    if ( !drive.stockedLight[i] )
      drive.rightMotor->SubPower(73);
    if ( !drive.stockedLight[3-i] )
      drive.leftMotor->SubPower(73);
  }

  // 速度値に従って車輪を回転させる
  drive.rightMotor->RotateWheel();
  drive.leftMotor->RotateWheel();
  
  delay(10);
}
