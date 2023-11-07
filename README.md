 # PCA9548 I2C Multiplexer Library

 This library allows for simple communication with the PCA9548 I2C multiplexer which enables control of up to eight I2C devices on the same bus. The library provides an easy-to-use interface for switching between devices or channels on the fly. 

 ## Installation

 Download the repository and place it in your Arduino libraries directory, or use the Arduino Library Manager to search for PCA9548 and install it directly. 

 ## Usage

 Include the PCA9548 library in your sketch and instantiate a PCA9548 object. You can start communication with the multiplexer by specifying its I2C address. If you want to initialize the library and start the Wire library at the same time, you can pass a second parameter when creating the PCA9548 object. 

 ```cpp 
#include <Wire.h>
#include <PCA9548.h>

uint8_t pcaAddress = 0x70;
PCA9548 pca(pcaAddress);
PCA9548 pca(pcaAddress, 1); // Initialize the library and start the Wire library
 ``` 

 In your setup function, start the I2C bus if you have not already done so in the object instantiation. 

 ```cpp 
void setup() {
  Wire.begin(); // Start the I2C bus if not already started
}
 ``` 

 In your main loop, you can switch between channels using the switchChannel() function, which accepts the channel number as an argument. You can also switch multiple channels on or off simultaneously with the switchAllChannels() function, which accepts a byte where each bit represents a channel. 

 ```cpp 
void loop() {
  pca.switchChannel(0);
  pca.switchChannel(1);
  // ...
  pca.switchAllChannels(0b10010001); // Example byte to switch multiple channels
}
 ``` 
