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
  DC40175();//empty contstructor
  void increment(int delayTime);// increment counter by setting once high and low. time in mills
  void setHigh(); // manually set high
  void setLow(); // manully set low
  void setHL(); // set high if low set low if high
  void inhibitClock(); // stop the clock
  void reset(); // reset all
  int carryOut(); // incoming signal
  int whichPin(); // which pin is active?
  int value; // the counted value
  ~DC40175();//deconstructor

};