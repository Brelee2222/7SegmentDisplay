#include <Arduino.h>

#define segmentLatch 8
#define segmentClock 9
#define segmentSerial 10

/**
 * @brief initializes the display pins
 * 
 */
void initSegDisp();

/**
 * @brief displays the register
 * 
 */
void dispReg();

/**
 * @brief writes the segment and moves to the next segment pos
 * 
 * @param on if segment is on or off
 */
void writeSeg(bool on);

/**
 * @brief sets segment position
 * 
 * @param pos new segment position
 */
void resetSegPos(char pos);

/**
 * @brief writes to the entire display with the given segments
 * 
 * @param segs 8-bit char with each bit place having the information to turn the led on or off
 */
void writeDisp(char segs);

/**
 * @brief loads the register information and skips @param skips segments
 * 
 * @param skips number of segments to skip
 */
void skipSegs(char skips);

/**
 * @brief turns pin on and off
 * 
 * @param pin pin to tick
 */
void tickPin(char pin);

/**
 * @brief clears the display and resets the position
 * 
 */
void resetDisplay();

/**
 * @brief goes to the new segment position
 * 
 * @param newPos new segment position
 */
void setSegPos(char newPos);