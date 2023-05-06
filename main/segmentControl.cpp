#include "segmentControl.h"

void initSegDisp() {
    pinMode(segmentLatch, OUTPUT);
	pinMode(segmentClock, OUTPUT);
	pinMode(segmentSerial, OUTPUT);
    digitalWrite(segmentLatch, HIGH);
    digitalWrite(segmentClock, LOW);
    digitalWrite(segmentSerial, LOW);
}

void tickPin(char pin) {
    digitalWrite(pin, LOW);
    digitalWrite(pin, HIGH);
}

void resetDisplay() {
    writeDisp(0);
    dispReg();
}

void dispReg() {
    tickPin(segmentLatch);
}

char segPos = 0;

void nextSeg() {
    tickPin(segmentClock);
    segPos++;
}

void skipSegs(char skips) {
    digitalWrite(segmentLatch, LOW);

    for(skips &= 0b111; skips; skips--) {
        nextSeg();
    }

    digitalWrite(segmentLatch, HIGH);

    segPos += skips;
}

void setSegPos(char newPos) {
    skipSegs(newPos - segPos);
}

void resetSegPos(char pos) {
    segPos = pos;
}

void writeSeg(boolean on) {
    digitalWrite(segmentSerial, on);
    nextSeg();
}

void writeDisp(char segs) {
    setSegPos(0);
    
    do {
        writeSeg(segs >> segPos & 1);
    } while(segPos);
}