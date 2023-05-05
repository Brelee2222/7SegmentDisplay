#include "segmentControl.h"

void initSegDisp() {
    pinMode(segmentLatch, OUTPUT);
	pinMode(segmentClock, OUTPUT);
	pinMode(segmentSerial, OUTPUT);
    digitalWrite(segmentLatch, HIGH);
    digitalWrite(segmentClock, HIGH);
    digitalWrite(segmentSerial, HIGH);
}

void tickPin(uint8_t pin) {
    digitalWrite(pin, LOW);
    digitalWrite(pin, HIGH);
}

void resetDisplay() {
    writeDisp(0b11111111);
    dispReg();
}

void dispReg() {
    tickPin(segmentLatch);
}

void nextSeg() {
    tickPin(segmentClock);
}

void writeSeg(boolean output) {
    digitalWrite(segmentSerial, output);
    nextSeg();
}

void writeDisp(byte segs) {
    int segPos = 0;
    while(++segPos != 7) {
        writeSeg(segs >> segPos & 1);
    }
}