#include "Arduino.h"
#include "DC40175.h"
   // * PIN 16 - V DC
   // * PIN 15 - RESET
   // * PIN 14 - CLOCK
   // * PIN 13 - CLOCK INHIBIT (STOP COUNTING)
   // * PIN 12 - CARRY OUT (INDICATE DECIMAL)
   // * PIN 11 - 9
   // * PIN 10 - 4
   // * PIN 09 - 8
   // * PIN 08 - GND
   // * PIN 07 - 3
   // * PIN 06 - 7
   // * PIN 05 - 6
   // * PIN 04 - 2
   // * PIN 03 - 0
   // * PIN 02 - 1
   // * PIN 01 - 5

DC40175::DC40175(int _clockpin){
clockpin = _clockpin;
  minimal = 0;
    value = 0;
    state = 0;
    // pinMode(clockpin, OUTPUT);
init(0);
reset();
}



DC40175::DC40175( int _clockpin,
                  int _resetpin,
                  int _inhibitpin,
                  int _carryoutpin){
  clockpin = _clockpin;
  resetpin = _resetpin;
  inhibitpin = _inhibitpin;
  carryoutpin = _carryoutpin;
  state = 0;
  minimal = 1;
  init(1);

}

  void DC40175::init(int mini){
    value = 0;
    pinMode(clockpin, OUTPUT);
    if(mini){
    pinMode(resetpin, OUTPUT);
    pinMode(inhibitpin, OUTPUT);
    pinMode(carryoutpin, INPUT);

    }
  }

  void DC40175::clock(){
    value++;
    state = 1;
  digitalWrite(clockpin,HIGH);
  delay(1);
  state = 0;
  digitalWrite(clockpin,LOW);
  }

  void DC40175::clock(int delayTime){
    value++;
    state = 1;
  digitalWrite(clockpin,HIGH);
  delay(delayTime);
  state = 0;
  digitalWrite(clockpin,LOW);
  }

  void DC40175::increment(int delayTime){
    value++;
    state = 1;
  digitalWrite(clockpin,HIGH);
  delay(delayTime);
  state = 0;
  digitalWrite(clockpin,LOW);
  }

  void DC40175::setHigh(){
  // manually set high

   value++;
  state = 1;
  digitalWrite(clockpin, HIGH);
  delay(1);
  }
  void DC40175::setLow(){
   // manully set low
   state = 0;
   digitalWrite(clockpin, LOW);
   delay(1);
  }
  void DC40175::setHL(){
   // set high if low set low if high
   value++;
    if(state){
      state = 0;
      digitalWrite(clockpin, LOW);
    }else{
      state = 1;
      digitalWrite(clockpin, HIGH);
    }
    delay(1);
  }

  void DC40175::inhibitClock(){
   // stop the clock
   if(minimal == 1){
    digitalWrite(inhibitpin, HIGH);
  }

  }
    void DC40175::resumeClock(){
   // resume the clock
   if(minimal == 1){
   digitalWrite(inhibitpin, LOW);
 }
  }
  void DC40175::reset(){
   // reset all
  if(minimal == 1){
  digitalWrite(resetpin,HIGH);
  delay(1);
  digitalWrite(resetpin,LOW);
  value = 0;
  }
  state = 0;
  }
  int DC40175::carryOut(){
   // incoming signal
   if(minimal == 1){
   return digitalRead(carryoutpin);
 }
  }
 //  int DC40175::whichPin(){
 // return value%11;
 //   // which pin is active?
  // }