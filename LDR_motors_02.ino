//LDR declaration
int LDRtl = A2; //top-left
int LDRtr = A3; //top-right
int LDRbl = A4; //bottom-left
int LDRbr = A5; //bottom-right
//LDR reading
int ldrtl;
int ldrtr;
int ldrbl;
int ldrbr;
//averages
int avgt; // average top
int avgb; //average bottom
int avgr; //average right
int avgl; //average left

// avg difference
int avgtb;
int avgrl;

//motors
//MOTOR 1
int MOTOR_A1_PIN = 7;
int MOTOR_B1_PIN = 8;
//MOTOR 2
int MOTOR_A2_PIN = 4;
int MOTOR_B2_PIN = 9;

int PWM_MOTOR_1 = 5;
int PWM_MOTOR_2 = 6;;

int EN_PIN_1 = A0;
int EN_PIN_2 = A1;

//safety
int push_1=10;
int push_2=13;
int pushreading_1;
int pushreading_2;

//switch
int flag=0;

void setup() {
  Serial.begin(9600);
  pinMode(LDRtl, INPUT);
  pinMode(LDRtr, INPUT);
  pinMode(LDRbl, INPUT);
  pinMode(LDRbr, INPUT);
  pinMode(push_1, INPUT);
  pinMode(push_2, INPUT);
  pinMode(MOTOR_A1_PIN, OUTPUT);
  pinMode(MOTOR_B1_PIN, OUTPUT);
  pinMode(MOTOR_A2_PIN, OUTPUT);
  pinMode(MOTOR_B2_PIN, OUTPUT);
  pinMode(PWM_MOTOR_1, OUTPUT);
  pinMode(PWM_MOTOR_2, OUTPUT);
  pinMode(EN_PIN_1, OUTPUT);
  pinMode(EN_PIN_2, OUTPUT);

}

void loop() {

  ldrtl = analogRead(LDRtl);
  ldrtr = analogRead(LDRtr);
  ldrbl = analogRead(LDRbl);
  ldrbl =ldrbl /2;
  ldrbr = analogRead(LDRbr);
  ldrbr =ldrbr /2;
/*  pushreading_1=digitalRead(push_1);
  pushreading_2=digitalRead(push_2);*/
  avgt = (ldrtl + ldrtr) / 2;
  avgb = (ldrbl + ldrbr) / 2;
  avgr = (ldrbr + ldrtr) / 2;
  avgl = (ldrbl + ldrtl) / 2;
  avgtb=abs(avgt-avgb);
  avgrl=abs(avgr-avgl);
  //stop
if (avgtb<70 ){
  if(avgrl<70){
      digitalWrite(EN_PIN_1, LOW);
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);
      analogWrite(PWM_MOTOR_1, 60);
      digitalWrite(EN_PIN_2, LOW);
      digitalWrite(MOTOR_A2_PIN, LOW);
      digitalWrite(MOTOR_B2_PIN, LOW);
      analogWrite(PWM_MOTOR_2, 60);
      Serial.println("stop");
      Serial.print(avgt);
      Serial.print(" ");
      Serial.print(avgb);
      Serial.print(" ");
      Serial.print(avgr);
      Serial.print(" ");
      Serial.println(avgl);
      Serial.print(" ");
}}
if (avgtb>70){
  //forward
   if (avgt > avgb) {
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, HIGH);
    analogWrite(PWM_MOTOR_1, 120);
    delay(50);
    digitalWrite(EN_PIN_1, LOW);
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, HIGH);
    analogWrite(PWM_MOTOR_1, 60);
    Serial.println("forward");
    Serial.print(avgt);
    Serial.print(" ");
    Serial.print(avgb);
    Serial.print(" ");
    Serial.print(avgr);
    Serial.print(" ");
    Serial.println(avgl);
    Serial.print(" ");
    delay(1000);
 
   /* pushreading_1=digitalRead(push_1);
    if(pushreading_1 == HIGH){
      digitalWrite(EN_PIN_1, HIGH);
      digitalWrite(MOTOR_A1_PIN, HIGH);
      digitalWrite(MOTOR_B1_PIN, LOW);
      delay(200);
      digitalWrite(EN_PIN_1, LOW);
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);
      Serial.println("stop");
      Serial.print(avgt);
      Serial.print(" ");
      Serial.print(avgb);
      Serial.print(" ");
      Serial.print(avgr);
      Serial.print(" ");
      Serial.println(avgl);
      Serial.print(" ");
      flag=1;
      
    }*/}
  //backward
  if (avgt < avgb ) {
    digitalWrite(EN_PIN_1, HIGH);
    digitalWrite(MOTOR_A1_PIN, HIGH);
    digitalWrite(MOTOR_B1_PIN, LOW);
    analogWrite(PWM_MOTOR_1, 120);
    delay(50);
    digitalWrite(EN_PIN_1, LOW);
    digitalWrite(MOTOR_A1_PIN, LOW);
    digitalWrite(MOTOR_B1_PIN, HIGH);
    analogWrite(PWM_MOTOR_1, 60);
    Serial.println("backward");
    Serial.print(avgt);
    Serial.print(" ");
    Serial.print(avgb);
    Serial.print(" ");
    Serial.print(avgr);
    Serial.print(" ");
    Serial.println(avgl);
    Serial.print(" ");
    delay(1000);
 
   /* pushreading_2=digitalRead(push_2);
      if(pushreading_2 == HIGH){
      digitalWrite(EN_PIN_1, HIGH);
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, HIGH);
      delay(200);
      digitalWrite(EN_PIN_1, LOW);
      digitalWrite(MOTOR_A1_PIN, LOW);
      digitalWrite(MOTOR_B1_PIN, LOW);
      Serial.println("stop");
      Serial.print(avgt);
      Serial.print(" ");
      Serial.print(avgb);
      Serial.print(" ");
      Serial.print(avgr);
      Serial.print(" ");
      Serial.println(avgl);
      Serial.print(" ");
      flag=1;
   
    }*/}}
      
   if(avgrl>70){
  //right
  if (avgr > avgl) {
    digitalWrite(EN_PIN_2, HIGH);
    digitalWrite(MOTOR_A2_PIN, LOW);
    digitalWrite(MOTOR_B2_PIN, HIGH);
    analogWrite(PWM_MOTOR_2, 80);
    delay(250);
    digitalWrite(EN_PIN_2, LOW);
    digitalWrite(MOTOR_A2_PIN, LOW);
    digitalWrite(MOTOR_B2_PIN, HIGH);
    analogWrite(PWM_MOTOR_2, 60);
    Serial.println("right");
    Serial.print(avgt);
    Serial.print(" ");
    Serial.print(avgb);
    Serial.print(" ");
    Serial.print(avgr);
    Serial.print(" ");
    Serial.println(avgl);
    Serial.print(" ");
    delay(1000);
    
  }
  //left
  if (avgr < avgl ) {
    digitalWrite(EN_PIN_2, HIGH);
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
    analogWrite(PWM_MOTOR_2, 80);
    delay(250);
    digitalWrite(EN_PIN_2, LOW);
    digitalWrite(MOTOR_A2_PIN, HIGH);
    digitalWrite(MOTOR_B2_PIN, LOW);
    analogWrite(PWM_MOTOR_2, 60);
    Serial.println("left");
    Serial.print(avgt);
    Serial.print(" ");
    Serial.print(avgb);
    Serial.print(" ");
    Serial.print(avgr);
    Serial.print(" ");
    Serial.println(avgl);
    Serial.print(" ");
    delay(1000);
     
      }}


}
