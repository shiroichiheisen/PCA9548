#include "Arduino.h"
#include "PCA9548.h"

PCA9548::PCA9548(uint8_t PCAaddress, bool beginWire)
{
  PCA9548Address = PCAaddress;
  if (beginWire)
    Wire.begin();
}

void PCA9548::switchChannel(uint8_t channel)
{
  Wire.beginTransmission(PCA9548Address);
  Wire.write(1 << channel);
  Wire.endTransmission();
}

void PCA9548::switchAllChannels(uint8_t channelsData)
{
  Wire.beginTransmission(PCA9548Address);
  Wire.write(channelsData);
  Wire.endTransmission();
}
