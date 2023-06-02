#ifndef PCA9548_h
#define PCA9548_h

#include "Arduino.h"
#include <Wire.h>

class PCA9548
{
public:
	PCA9548(uint8_t PCAaddress);
	void switchChannel(uint8_t channel);

private:
	uint8_t PCA9548Address;
};

#endif
