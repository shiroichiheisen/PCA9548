#ifndef PCA9548_h
#define PCA9548_h

#include "Arduino.h"
#include <Wire.h>

class PCA9548
{
public:
	PCA9548(uint8_t PCAaddress, bool beginWire = false);
	void switchChannel(uint8_t channel);
	void switchAllChannels(uint8_t channelsData);

private:
	uint8_t PCA9548Address;
};

#endif
