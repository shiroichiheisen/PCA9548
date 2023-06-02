#include "Arduino.h"
#include "PCA9548A.h"

PCA9548A::PCA9548A(uint8_t PCAaddress)
{
  PCA9548Address = PCAaddress;
}

void PCA9548A::switchChannel(uint8_t channel)
{
  Wire.beginTransmission(PCA9548Address);
  Wire.write(1 << channel);
  Wire.endTransmission();
}
