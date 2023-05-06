#include "segmentControl.h"

byte digits[]{
    0b11011110,
    0b00000110,
    0b10111010,
    0b10101110,
    0b01100110,
    0b11101100,
    0b11111100,
    0b10000110,
    0b11111110,
    0b11101110,
    0b11110110,
    0b01111100,
    0b11011000,
    0b00111110,
    0b11111000,
    0b11110000
};

void setup()
{
	initSegDisp();

    resetDisplay();

    writeDisp(digits[3]);

    setSegPos(5);
    writeSeg(false);

    setSegPos(4);
    writeSeg(true);

    setSegPos(6);
    writeSeg(true);

    setSegPos(3);
    writeSeg(false);

    setSegPos(0);
    writeSeg(true);

    dispReg();
}

void loop()
{
    // dispDigit(&count);
    // delay(1000);
}

char count = 0;

// dispDigit has the digit param for any special use for the display.
void dispDigit(char* digit) {
    writeDisp(digits[*digit & 0xf]);

    *digit += 1;

    dispReg();
}