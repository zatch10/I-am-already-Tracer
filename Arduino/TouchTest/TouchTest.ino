/*************************************************** 
  This is an example for the Adafruit STMPE610 Resistive
  touch screen controller breakout
  ----> http://www.adafruit.com/products/1571
 
  Check out the links above for our tutorials and wiring diagrams
  These breakouts use SPI or I2C to communicate

  Adafruit invests time and resources providing this open source code,
  please support Adafruit and open-source hardware by purchasing
  products from Adafruit!

  Written by Limor Fried/Ladyada for Adafruit Industries.
  MIT license, all text above must be included in any redistribution
 ****************************************************/

#include <Wire.h>

#include "Adafruit_STMPE610.h"
#include <Stepper.h>
#define STEPS 200

// Pick one of three wiring options below!

// uses I2C, connect to hardware I2C port only!
// SCL to I2C clock (#A5 on Uno) and SDA to I2C data (#A4 on Uno)
// tie MODE to GND and POWER CYCLE (there is no reset pin)
Adafruit_STMPE610 touch = Adafruit_STMPE610();
Stepper stepper(STEPS, 2,4,6,7);
int previous = 0;
/******************/

void setup() { 
  stepper.setSpeed(100);
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
  uint16_t x, y;
  uint8_t z;
  if (touch.touched()) {
    // read x & y & z;
    while (! touch.bufferEmpty()) {
      Serial.print(touch.bufferSize());
      touch.readData(&x, &y, &z);
      Serial.print("->("); 
      Serial.print(x); Serial.print(", ");
      Serial.print(y); Serial.print(", ");
      Serial.print(z);
      Serial.println(")");
      move_step_x(y);
    }
    touch.writeRegister8(STMPE_INT_STA, 0xFF); // reset all ints, in this example unneeded depending in use
  }
  delay(10);
}
