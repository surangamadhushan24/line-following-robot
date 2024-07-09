

// motor controlling
#define LMF 12
#define LMB 11
#define LMS 10
#define RMF 8
#define RMB 7
#define RMS 9

// IR sensor pins
#define IR1  2
#define IR2  3
#define IR3  4 
#define IR4  5
#define IR5  6

void setup() {
 


   // Motor pins setup
  for (int i = 7; i < 13; i++) {
    pinMode(i, OUTPUT);
  }

// Sensor pins setup
  for (int j = 2; j < 7; j++) {
    pinMode(j, INPUT);
  
  }
}

void loop() {

  int leftmost = digitalRead(IR1);
  int left = digitalRead(IR2);
  int center = digitalRead(IR3);
  int right = digitalRead(IR4);
  int rightmost = digitalRead(IR5);

 

if(center==1){
  moveForward();
}
else if(right==1){
  turnRightSlowly();
}
else if(left==1){
turnLeftSlowly();
}
else if(leftmost==1){
  turnLeftSharp();
}

else if(rightmost==1){
turnRightSharp();
}

else if(left == 0 && right==0 && center==0 && leftmost==0 && rightmost==0){
  Mbackward();
  
}
else if(left == 1 && right==1 && center==1 && leftmost==1 && rightmost==1){
   Mstop();
}


}

void moveForward() {
 digitalWrite(LMF,1);
 digitalWrite(LMB,0);
 analogWrite(LMS,100);
 digitalWrite(RMF,1);
 digitalWrite(RMB,0);
 analogWrite(RMS,100);

}

void turnRightSlowly(){
 digitalWrite(LMF,1);
 digitalWrite(LMB,0);
 analogWrite(LMS,100);
 digitalWrite(RMF,1);
 digitalWrite(RMB,0);
 analogWrite(RMS,50);
}

void turnLeftSlowly(){
   digitalWrite(LMF,1);
 digitalWrite(LMB,0);
 analogWrite(LMS,50);
 digitalWrite(RMF,1);
 digitalWrite(RMB,0);
 analogWrite(RMS,100);
}

void Mbackward(){
 digitalWrite(LMF,0);
 digitalWrite(LMB,1);
 analogWrite(LMS,100);
 digitalWrite(RMF,0);
 digitalWrite(RMB,1);
 analogWrite(RMS,100);
 }

 void turnRightSharp() {
  digitalWrite(LMF, 1);
  digitalWrite(LMB, 0);
  analogWrite(LMS, 100);
  digitalWrite(RMF, 0);
  digitalWrite(RMB, 1);
  analogWrite(RMS, 100);
}

void turnLeftSharp() {
  digitalWrite(LMF, 0);
  digitalWrite(LMB, 1);
  analogWrite(LMS, 100);
  digitalWrite(RMF, 1);
  digitalWrite(RMB, 0);
  analogWrite(RMS, 100);
}

void Mstop(){
 digitalWrite(LMF,1);
 digitalWrite(LMB,1);
 analogWrite(LMS,100);
 digitalWrite(RMF,1);
 digitalWrite(RMB,1);
 analogWrite(RMS,100);
}




