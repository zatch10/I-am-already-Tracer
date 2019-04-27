/*#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 200
//Purple:7;Blue:6;Green:4; Brown:2;
//On motor: <motorwire:ard_wire> :: black:green; green:yellow; red:blue; blue:orange;
// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 2,4,6,7);

// the previous reading from the analog input
int previous = 0;

void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(50);
  Serial.begin(9600);
}
*/
void move_step_x(int input) {
  
  // get the sensor value
  int val = map(input,0,3000,0,STEPS);

  // move a number of steps equal to the change in the
  // sensor reading
  //Serial.println(val-previous);
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
}
