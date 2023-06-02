# PCA9548 Library

To use this library:

```
uint8_t pcaAdress = 0x70;

PCA9548 pca(pcaAdress);
PCA9548 pca(pcaAdress, 1); // to inicialize the library and start the wire library

void loop() {
  pca.selectChannel(0);
  pca.selectChannel(1);
  pca.selectChannel(2);
  pca.selectChannel(3);
  pca.selectChannel(4);
  pca.selectChannel(5);
  pca.selectChannel(6);
  pca.selectChannel(7);
}
```