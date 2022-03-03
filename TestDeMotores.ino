int motor1 = 2;
int motor2 = 3;
int motor3 = 4;
int motor4 = 5;
int counter = 0;

void setup() {
  Serial.begin(9600);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  digitalWrite(motor1, LOW);
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);
  digitalWrite(motor4, LOW);
}

void loop() {

  counter = counter * 1;
  delay(100)
  
  while (){
  analogWrite(motor1, 225);
  analogWrite(motor2, 225);
  analogWrite(motor3, 225);
  analogWrite(motor4, 225);
  delay(100);

  analogWrite(motor1, LOW);
  analogWrite(motor2, LOW);
  analogWrite(motor3, LOW);
  analogWrite(motor4, LOW);
  delay(1000);

  //
  analogWrite(motor1, 225);
  analogWrite(motor2, 225);
  analogWrite(motor3, 225);
  analogWrite(motor4, 225);
  delay(100);

  analogWrite(motor1, LOW);
  analogWrite(motor2, LOW);
  analogWrite(motor3, LOW);
  analogWrite(motor4, LOW);
  delay(1000);
  
  //
  analogWrite(motor1, 225);
  analogWrite(motor2, 225);
  analogWrite(motor3, 225);
  analogWrite(motor4, 225);
  delay(100);

  analogWrite(motor1, LOW);
  analogWrite(motor2, LOW);
  analogWrite(motor3, LOW);
  analogWrite(motor4, LOW);
  delay(1000);
  }
  texto = digitalRead("Escribe algo");
}
