# PCA9548 Library

To use this library:

```
uint8_t pcaAdress = 0x70;

PCA9548 pca(pcaAdress);
PCA9548 pca(pcaAdress, 1); // to inicialize the library and start the wire library

void loop() {
  pca.switchChannel(0);
  pca.switchChannel(1);
  pca.switchChannel(2);
  pca.switchChannel(3);
  pca.switchChannel(4);
  pca.switchChannel(5);
  pca.switchChannel(6);
  pca.switchChannel(7);
  // Or sending a byte for selecting the channels
  pca.switchAllChannels(0b10010001);
}
```