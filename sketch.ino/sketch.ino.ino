void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  int a1=0,a2=0,b1=0,b2=0,X=0,Y=0,x1=0,y1=0,x2=0,y2=0;
  //uint16_t x, y;
  uint8_t z;
  while(true){
    if (touch.touched()) {
    // read x & y & z;
    while (! touch.bufferEmpty()) {
      Serial.print(touch.bufferSize());
      touch.readData(&x2, &y2, &z);
      Serial.print("->("); 
      Serial.print(x); Serial.print(", ");
      Serial.print(y); Serial.print(", ");
      Serial.print(z);
      Serial.println(")");
      a1 = sqrt(pow(x1,2)+pow(Y-y1,2));
      a2 = sqrt(pow(x2,2)+pow(Y-y2,2));
      b1 = sqrt(pow(X-x1,2)+pow(Y-y1,2));
      b2 = sqrt(pow(X-x2,2)+pow(Y-y2,2));
      //val1, val2
      int l = max(val1,val2);
      for(int i=0; i<l; i++){
        if(i<val1){
         move_step_x(1);
      }
      if(i<val2){
         move_step_y(1);
      }
      move_step_x(y);
      x1=x2;
      y1=y2;
    }
    touch.writeRegister8(STMPE_INT_STA, 0xFF); // reset all ints, in this example unneeded depending in use
  }
  }

}
