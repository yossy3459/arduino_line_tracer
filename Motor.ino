#include "Exec06.h"

// コンストラクタ
Motor::Motor(int selectedDir)
{
  power = 150;
  dir = selectedDir;
}

// モーターに回転速度をセット
void Motor::SetPower(int powerValue)
{
  power = powerValue;
}

// モータの回転速度を引数の分だけ引く
void Motor::SubPower(int powerValue)
{
  power -= powerValue;
}

// モーターを回転させる
void Motor::RotateWheel()
{
  analogWrite(dir, power);
}
