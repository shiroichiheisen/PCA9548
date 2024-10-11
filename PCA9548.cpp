#include "Arduino.h"
#include "PCA9548.h"

PCA9548::PCA9548(uint8_t PCAaddress, bool beginWire)
{
  PCA9548Address = PCAaddress;
  if (beginWire)
    Wire.begin();
}

void PCA9548::switchAddress(uint8_t PCAaddress)
{
  PCA9548Address = PCAaddress;
}

bool PCA9548::switchChannel(uint8_t channel, uint8_t retries)
{
  for (uint8_t attempt = 0; attempt < retries; attempt++)
  {
    if (isBusFree())
    {
      Wire.beginTransmission(PCA9548Address);
      Wire.write(1 << channel);

      if (Wire.endTransmission() == 0)
        return true;
    }
    delay(50);
  }
  return false;
}

bool PCA9548::switchAllChannels(uint8_t channelsData, uint8_t retries)
{
  for (uint8_t attempt = 0; attempt < retries; attempt++)
  {
    if (isBusFree())
    {
      Wire.beginTransmission(PCA9548Address);
      Wire.write(channelsData);
      if (Wire.endTransmission() == 0)
        return true;
    }
    delay(50);
  }

  return false;
}

bool PCA9548::isBusFree()
{
  Wire.beginTransmission(PCA9548Address);
  uint8_t result = Wire.endTransmission();
  return (result == 0);
}