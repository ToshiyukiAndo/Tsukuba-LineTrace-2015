// モーター制御
const int border = 570;

const int motorA = 8;//前進右
const int motorB = 6;//前進左
const int PWM_motAB = 9;
const int motorC = 10;//バック右
const int motorD = 5;//バック左
const int PWM_motCD = 11;
const int analogPin1 = A5;
const int analogPin2 = A4;
const int sensorPin = 13;

int backFlag = 0;

const int vPin = 0;

int val = 0;
int val2 = 0;
void setup(){

  Serial.begin(9600);

  pinMode(sensorPin, OUTPUT);
  digitalWrite(sensorPin, HIGH);
  pinMode(analogPin1, INPUT);//入力ピン
  pinMode(motorA,OUTPUT); //信号用ピン
  pinMode(motorB,OUTPUT); //信号用ピン
  pinMode(motorC,OUTPUT); //信号用ピン
  pinMode(motorD,OUTPUT); //信号用ピン

  pinMode(vPin, OUTPUT);
}

void loop(){

  int val, val2 = 0;

  char s[128];
    val = analogRead(analogPin1);
    val2 = analogRead(analogPin2);

  digitalWrite(vPin, HIGH);

if(val < border && val2 < border){
  //線から外れた時、バック
  digitalWrite(motorA,LOW);
  digitalWrite(motorB,HIGH);
  digitalWrite(motorC,LOW);
  digitalWrite(motorD,HIGH);

}else if(val < border && val2 > border){
  //左回転
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
  digitalWrite(motorC, LOW);
  digitalWrite(motorD, LOW);
}else if(val > border && val2 < border){
  //右回転
  digitalWrite(motorA, LOW);
  digitalWrite(motorB, LOW);
  digitalWrite(motorC, HIGH);
  digitalWrite(motorD, LOW);
}else{
  //直進
  digitalWrite(motorA, HIGH);
  digitalWrite(motorB, LOW);
  digitalWrite(motorC, HIGH);
  digitalWrite(motorD, LOW);
}

//if(val >= 450){
//  digitalWrite(motorA, HIGH);
//  digitalWrite(motorC, HIGH);
//  //delay(10);
//}
//  digitalWrite(motorA,LOW);
//  digitalWrite(motorC,LOW);
  delay(10);

  sprintf(s,"%4d,%4d", val,val2);
  Serial.println(s);
}
