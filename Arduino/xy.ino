/*
* MotorKnob * * A stepper motor follows the turns of a potentiometer * (or other sensor) on analog input 0. * * http://www.arduino.cc/en/Reference/Stepper * This example code is in the public domain. */

#include

// change this to the number of steps on your motor #define STEPS 100

// create an instance of the stepper class, specifying // the number of steps of the motor and the pins it's // attached to Stepper stepper(STEPS, 8, 9, 10, 11); Stepper stepper2(STEPS, 3, 4, 5, 6);

// the previous reading from the analog input int previous = 0;

void setup() {

// set the speed of the motor to 100 RPMs

stepper.setSpeed(100);
stepper2.setSpeed(100);
Serial.begin(9600);
}

void loop() {

int lr = analogRead(A0);
int ud = analogRead(A1);
Serial.println("------------------------------------");
Serial.print ("LR: ");
Serial.println(lr);
Serial.print ("UD: ");
Serial.println(ud);
delay(100);
// get the sensor value

int val = analogRead(0);

if(val > 525) {
stepper.step(1);
}

else if(val < 475) {
stepper.step(-1);

}

int val2 = analogRead(1);
if(val2 > 525) {
stepper2.step(1);
}

else if(val2 < 475) {
stepper2.step(-1);
}

// remember the previous value of the sensor

previous = val; }
