#include <Wire.h>

#include "Adafruit_STMPE610.h"
#include <Stepper.h>
#define STEPS 200
#define SPL 61.515748

// Pick one of three wiring options below!

// uses I2C, connect to hardware I2C port only!
// SCL to I2C clock (#A5 on Uno) and SDA to I2C data (#A4 on Uno)
// tie MODE to GND and POWER CYCLE (there is no reset pin)
Adafruit_STMPE610 touch = Adafruit_STMPE610();
Stepper stepper(STEPS, 2,3,4,5);
Stepper stepper2(STEPS, 8,9,10,11);
int previous = 0;
/******************/

void setup() { 
  stepper.setSpeed(200);
  Serial.begin(9600);
  Serial.println("Adafruit STMPE610 example");
  Serial.flush();

  // if using hardware SPI on an Uno #10 must be an output, remove line
  // if using software SPI or I2C
  //pinMode(10, OUTPUT); -> (Vatsin's note: I am pretty sure this is not needed for I2C as I2C has all fixed pins...... Bik gai hai gormint, baith ke chutiya bana rahe hai humko madarchod ke bachche)

  // If using I2C you can select the I2C address (there are two options) by calling
  // touch.begin(0x41), the default, or touch.begin(0x44) if A0 is tied to 3.3V
  // If no address is passed, 0x41 is used
  if (! touch.begin()) {
    Serial.println("STMPE not found!");
    while(1);
  }
  Serial.println("Waiting for touch sense");
}


void loop() {
  // put your main code here, to run repeatedly:
  int a1=40,a2=0,b1=72.111,b2=0,X=60,Y=40,x1=0,y1=0,x2=0,y2=0;
  //uint16_t x, y;
  uint8_t z;
  while(true){
    if (touch.touched()) {
    // read x & y & z;
    while (! touch.bufferEmpty()) {
      Serial.print(touch.bufferSize());
      touch.readData(&x2, &y2, &z);
      //touch.writeRegister8(STMPE_INT_STA, 0xFF); // reset all ints, in this example unneeded depending in use
      Serial.print("->("); 
      
      x2 = map(x2,325,3400,0,40);
      y2 = map(y2,325,3400,0,60);
      Serial.print(x2); Serial.print(", ");
      Serial.print(y2); Serial.print(", ");
      Serial.print(z);
      Serial.println(")");
      a1 = sqrt(pow(x1,2)+pow(Y-y1,2));
      a2 = sqrt(pow(x2,2)+pow(Y-y2,2));
      b1 = sqrt(pow(X-x1,2)+pow(Y-y1,2));
      b2 = sqrt(pow(X-x2,2)+pow(Y-y2,2));
      //val1, val2
      int val1 = (a2-a1)*SPL;
      int val2 = (b2-b1)*SPL;
      int sign1=1;
      int sign2=1;
      if(val1<0){
        val1 = val1*(-1);
        sign1=-1;
      }
      if(val2<0){
        val2 = val2*(-1);
        sign2=-1;
      }
      int l = max(val1,val2);
      for(int i=0; i<l; i++){
        if(i<val1){
         stepper.step(sign1);
      }
      if(i<val2){
         stepper2.step(sign2);
      }
     
      x1=x2;
      y1=y2;
    }
    touch.writeRegister8(STMPE_INT_STA, 0xFF); // reset all ints, in this example unneeded depending in use
  }
  }

}

}
