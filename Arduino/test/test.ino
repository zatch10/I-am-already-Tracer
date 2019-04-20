/*=================================

This code demostrates 4-Wire Touch screen

interfacing with Arduino

 

blog.circuits4you.com

www.circuits4you.com

 

4- Wire Touchscreen Connections

A0=====X+

A1=====X-

A2=====Y+

A3=====Y-

=================================*/

//Define your Touch screen connections

//#define A0 X1

//#define A1 X2

//#define A2 Y1

//#define A3 Y2

//Define your screen resolution as per your Touch screen (Max: 1024)

#define Xresolution 1024 //128

#define Yresolution 720 //64

 

void setup()

{

   Serial.begin(9600);

}

 

void loop()

{

  int X,Y; //Touch Coordinates are stored in X,Y variable

   pinMode(A2,INPUT);

   pinMode(A3,INPUT);

   digitalWrite(A3,LOW);

   pinMode(A0,OUTPUT);

   digitalWrite(A0,HIGH);

   pinMode(A1,OUTPUT);

   digitalWrite(A1,LOW);

   X = (analogRead(A2))/(1024/Xresolution); //Reads X axis touch position

 

   pinMode(A0,INPUT);

   pinMode(A1,INPUT);

   digitalWrite(A1,LOW);

   pinMode(A2,OUTPUT);

   digitalWrite(A2,HIGH);

   pinMode(A3,OUTPUT);

   digitalWrite(A3,LOW);

   Y = (analogRead(A0))/(1024/Yresolution); //Reads Y axis touch position

 

  //Display X and Y on Serial Monitor

   Serial.print("X = ");

   Serial.print(X);

   Serial.print(" Y = ");

   Serial.println(Y);

   delay(100);

}
