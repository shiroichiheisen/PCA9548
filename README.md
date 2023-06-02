# Utils Various Arduino

Library for the PCA9548A.

## ☕ Using this library

To use this library:

```
uint8_t pcaAdress = 0x70;

PCA9548A pca(pcaAdress);

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