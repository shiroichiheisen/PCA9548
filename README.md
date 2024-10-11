 # PCA9548 I2C Multiplexer Library (Now with the multiple master support!)

 This library allows for simple communication with the PCA9548 I2C multiplexer which enables control of up to eight I2C devices on the same bus. The library provides an easy-to-use interface for switching between devices or channels on the fly. 

The library have been updated to support multiple masters on the same bus.

 ## Installation

 Download the repository and place it in your Arduino libraries directory. 

 ## Usage

 Include the PCA9548 library in your sketch and instantiate a PCA9548 object. You can start communication with the multiplexer by specifying its I2C address. If you want to initialize the library and start the Wire library at the same time, you can pass a second parameter when creating the PCA9548 object. 

 ```cpp 
#include <Wire.h>
#include <PCA9548.h>

uint8_t pcaAddress = 0x70;
PCA9548 pca(pcaAddress);
PCA9548 pca(pcaAddress, 1); // Initialize the library and start the Wire library

// In your setup function, start the I2C bus if you have not already done so in the object instantiation. 

void setup() {
  Wire.begin(); // Start the I2C bus if not already started
  pca.switchAddress(0x20); // If you want to change the previous address to a new one
}
 
// In your main loop, you can switch between channels using the switchChannel() function, which accepts the channel number as an argument. You can also switch multiple channels on or off simultaneously with the switchAllChannels() function, which accepts a byte where each bit represents a channel. 

// The functions switchChannel() and switchAllChannels() have an optional second argument that specifies the number of times to try sending the command if the channel is detected as busy. The default is 3. If the bus is busy, the function will try to send the command again up to the specified number of times, if the channel is still busy after that, the function will return false. If the function is successful to send the command, it will return true.
 
void loop() {
  pca.switchChannel(0);
  pca.switchChannel(1);
  
  pca.switchChannel(0, 10); // Switch channel 0 and try to send 10 times if the channel is detected as busy (default is 3)
  // ...
  pca.switchAllChannels(0b10010001); // Example byte to switch multiple channels

  pca.switchAllChannels(0b10010001, 10); // Switch multiple channels and try to send 10 times if the channel is detected as busy (default is 3)
}
 ``` 
