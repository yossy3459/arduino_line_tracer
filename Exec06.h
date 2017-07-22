#ifndef EXEC06_H
#define EXEC06_H

// Sensorクラス
class Sensor{
  public:
    Sensor();
    bool Enabled(int);
    
  private:
    int value;
    int boundary;
};

// Motorクラス
class Motor{
  public:
    Motor(int);
    void SetPower(int);
    void SubPower(int);
    void RotateWheel();
    
  private:
    int power;
    int dir;
};

// Driveクラス
class Drive{
  public:
    void Stored();
    ~Drive();
    
  public:
    Sensor sensor;
    Motor* leftMotor = new Motor(5);
    Motor* rightMotor = new Motor(6);
    bool stockedLight[4];
};

#endif
