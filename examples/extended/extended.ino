#include <DC40175.h>


/*
 * Pin Functions CD4017B
 *
 * PIN 16 - V DC
 * PIN 15 - RESET
 * PIN 14 - CLOCK
 * PIN 13 - CLOCK INHIBIT (STOP COUNTING) not used need to be GND
 * PIN 12 - CARRY OUT (INDICATE DECIMAL) not used need to be GND
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

int clockpin = 2; // Arduino output
int resetpin = 8; // Arduino output
int inhibitpin = 9; // Arduino output
int carryoutpin = 10; // Arduino input
// initiate the full counter
DC40175 dcounter( clockpin,resetpin,inhibitpin,carryoutpin);

void setup(){
Serial.begin(9600);
dcounter.reset(); // reset to zero counter keeps track of state
}
void loop(){
  Serial.print("Counter value  ");
  Serial.println(dcounter.value); // readthe value
  dcounter.setHigh(); // set manually high
  delay(50);
  dcounter.setLow(); // manually low
  delay(500);
//  dcounter.setHL(); // set to the opposite

  /**
   * Read from the carryout pin input
   */
  if(dcounter.carryOut()){

    Serial.println("carry out is high");
  }else{
    Serial.println("carry out is low");
  }

  if(dcounter.value%24 == 0){
    dcounter.inhibitClock();// stop the clock
    delay(1000);
    dcounter.resumeClock();
    Serial.println("\nStopped clock for 1000 millis\nRESET DC40175\n");
    dcounter.reset(); // reset again

  }
}
