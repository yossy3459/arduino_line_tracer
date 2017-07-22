#include "Exec06.h"

// pin == A0 | A1 | A2 | A3
//        14 | 15 | 16 | 17

void Drive::Stored()
{
  // 宣言
  bool tmpLight[4];
  int keyFrame[4] = {14,15,16,17};
  bool flag = false;

  // tmpLight[i]に、白か黒かの判定を代入
  // true == 黒
  // false == 白
  for ( int i=0 ; i<4 ; i++ ){
    tmpLight[i] = sensor.Enabled(keyFrame[i]);

    // 黒があった場合、flagを立てる
    if ( tmpLight[i] )
      flag = true;
  }

  // flagが立った場合 (一つでも黒があった場合) -> stockedLight更新
  if ( flag )
    for ( int i=0 ; i<4 ; i++ )
      stockedLight[i] = tmpLight[i];
}

// デストラクタ
Drive::~Drive()
{
  delete leftMotor;
  delete rightMotor;
}
