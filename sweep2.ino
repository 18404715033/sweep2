#include <Servo.h>
Servo sv5; // 建立Servo物件，控制伺服馬達
Servo sv9;
const int sv5Pin = 8;  // sv5 接 Pin 8
const int sv9Pin = 9;  // sv9 接 Pin 9
const int every555 = 15;
const int every999 = 50;
unsigned long last555 = 0;
unsigned long last999 = 0; // last moving time
int dir5 = 1;
int dir9 = -1;
int pos555 = 90;
int pos999 = 90;
void setup() { 
   sv9.attach(sv9Pin); // 連接數位腳位9，伺服馬達(舵機)的訊號線
   sv5.attach(sv5Pin); // pin8, 故意名稱叫 sv5
   Serial.begin(9600);
   sv9.write(pos999);
   sv5.write(pos555);
   Serial.println("Test 2 Serbo");
   delay(50);
} 
void loop( ) {
  check555( );
  check999( );
  check888( );
}
void check555( ) {
   if(millis( ) - last555 < every555) return; // 還沒到
   last555 = millis( );
   pos555 += dir5;
   sv5.write(pos555);
   if(dir5 == 1){
      if(pos555 >179) dir5 = -1;
   }else{
      if(pos555 < 1) dir5 = 1;
   }
}
void check999( ) {
   if(millis( ) - last999 < every999) return; // 還沒到
   last999 = millis( );
   pos999 += dir9;
   sv9.write(pos999);
   if(dir9 == 70){
      if(pos999 >179) dir9 = -1;
   }else{
      if(pos999 < 1) dir9 = 1;
   }
}
void check888( ) {
  // more Servo ?
}
