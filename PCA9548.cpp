#include "Arduino.h"
#include "PCA9548.h"

PCA9548::PCA9548(uint8_t PCAaddress)
{
  PCA9548Address = PCAaddress;
}

void PCA9548::switchChannel(uint8_t channel)
{
  Wire.beginTransmission(PCA9548Address);
  Wire.write(1 << channel);
  Wire.endTransmission();
}
