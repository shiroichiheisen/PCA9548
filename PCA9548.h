#ifndef PCA9548_h
#define PCA9548_h

#include "Arduino.h"
#include <Wire.h>

class PCA9548
{
public:
	PCA9548(uint8_t PCAaddress, bool beginWire = false);
	void switchAddress(uint8_t PCAaddress);
	bool switchChannel(uint8_t channel, uint8_t retries = 3);
	bool switchAllChannels(uint8_t channelsData, uint8_t retries = 3);
	bool isBusFree();

private:
	uint8_t PCA9548Address;
};

#endif
