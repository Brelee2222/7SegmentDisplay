#include <Arduino.h>

#define segmentLatch 8
#define segmentClock 9
#define segmentSerial 10

void initSegDisp();
void dispReg();
void writeSeg(boolean output);
void redefineSegPos(uint8_t pos);
int getCurrentSeg();
void writeDisp(byte segs);
void skipSegs(byte segs);