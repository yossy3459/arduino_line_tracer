#include "Exec06.h"

// pin == A0 | A1 | A2 | A3
//        14 | 15 | 16 | 17

// コンストラクタ
Sensor::Sensor()
{
  value = 0;
  boundary = 100;
}

// 光センサーの値を読み取り、閾値と比較する
// 返り値: true == 黒
//        false == 白
bool Sensor::Enabled(int pin)
{
  value = analogRead(pin);
  if ( value < boundary )
    return false;
  else
    return true;
}
