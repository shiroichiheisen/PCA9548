#ifndef PCA9548A_h
#define PCA9548A_h

#include "Arduino.h"
#include <Wire.h>

class PCA9548A
{
public:
	PCA9548A(uint8_t PCAaddress);
	void switchChannel(uint8_t channel);

private:
	uint8_t PCA9548Address;
};

#endif
