#ifndef DC40175_h
#define DC40175_h
#include "Arduino.h"

class DC40175{
  /**
   * This should be a class for the
   * DC40175 Decade Counter
   * http://www.ti.com/lit/ds/symlink/cd4017b.pdf
   * License MIT
   *
   * Pin Functions CD4017B
   *
   * PIN 16 - V DC
   * PIN 15 - RESET
   * PIN 14 - CLOCK
   * PIN 13 - CLOCK INHIBIT (STOP COUNTING)
   * PIN 12 - CARRY OUT (INDICATE DECIMAL)
   * PIN 11 - 9
   * PIN 10 - 4
   * PIN 09 - 8
   * PIN 08 - GND
   * PIN 07 - 3
   * PIN 06 - 7
   * PIN 05 - 6
   * PIN 04 - 2
   * PIN 03 - 0
   * PIN 02 - 1
   * PIN 01 - 5
   */
public:
  DC40175(int _clockpin);//minmal contstructor
  DC40175( int _clockpin,
                  int _resetpin,
                  int _inhibitpin,
                  int _carryoutpin);//full contstructor

  /**
   * set one higher
   */
  void clock();
  void clock(int delayTime);

  /**
   * increment counter by setting once high and low.
   * similar to clock but you can define the time
   * @param delayTime time in mills
   */
  void increment(int delayTime);
  void setHigh(); // manually set high
  void setLow(); // manully set low
  void setHL(); // set high if low set low if high
  void inhibitClock(); // stop the clock
  void resumeClock(); // resume counting
  void reset(); // reset all

  int carryOut(); // incoming signal
  // int whichPin(); // which pin is active?
  int value; // the counted value

private:
int clockpin;
int resetpin;
int inhibitpin;
int carryoutpin;
int state;
int minimal;
void init(int mini);

};

#endif
