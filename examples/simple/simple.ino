#include <DC40175.h>

DC40175 dccounter(2);

void setup(){
Serial.begin(9600);  
}

void loop(){

  dccounter.clock();
  Serial.println("clock");
  Serial.println(dccounter.value);
  delay(100);
  
}
