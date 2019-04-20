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

//calculate an offset for using the RTO values. 
//lets say 3*RTO_x = pic_x and 4*RTO_y = pic_y and max_y = 500 and max_x = 500 -> these need to be the middle of the picture 
//the stepper will calibrate to the center of the image
//recieve pic_x or pic_y,
//store x = 3*pic_x, store y = 5*pic_y
//calculate offset by doing max_x - pic_x and for y
//then loop that many times to move that many points with stepperx.step(x) and steppery.step(y)
//will have to test out how to use delay to ensure this happens smoothly

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
