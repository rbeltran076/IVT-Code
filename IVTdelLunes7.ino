// VARIABLES
int trig1 = 2;
int echo1 = 3;
int trig2 = 4;
int echo2 = 5;
int trig3 = 6;
int echo3 = 7;
int trig4 = 8;
int echo4 = 9;
 
int motorPin1 = 10;
int motorPin2 = 11;
int motorPin3 = 12;
int motorPin4 = 13;
int counter = 0;
int dist1, inten1, dist2, inten2, dist3, inten3, dist4, inten4;

// SETUP
void setup()
{
  Serial.begin (9600);

//Definir los O e I
  pinMode (trig1, OUTPUT);
  pinMode (echo1, INPUT);
  pinMode (trig2, OUTPUT);
  pinMode (echo2, INPUT);
  pinMode (trig3, OUTPUT);
  pinMode (echo3, INPUT);
  pinMode (trig4, OUTPUT);
  pinMode (echo4, INPUT);
 
//Activar los sensores de proximidad.
  digitalWrite (trig1, LOW);
  digitalWrite (trig2, LOW);
  digitalWrite (trig3, LOW);
  digitalWrite (trig4, LOW);

// Definir los O e I de los motores
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

// Vibracion de bienvenida
  analogWrite(motorPin1, 75);
  analogWrite(motorPin2, 75);
  delay(100);
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  delay(100);
  analogWrite(motorPin1, 75);
  analogWrite(motorPin2, 75);
  delay(100);
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  delay(1000);
}

// Funcion MEASURE
int measure(int trig, int echo)
{
  int tiempo;
  digitalWrite (trig, HIGH);
  delay (100);
  digitalWrite (trig, LOW);
  tiempo = pulseIn (echo, HIGH);
  return tiempo / 58;
}

// LOOP
void loop()
{
  // Medidas de distancias de los sensores 1 y 2
  dist1 = measure(trig1, echo1);
  dist2 = measure(trig2, echo2);
  dist3 = measure(trig3, echo3);
  dist4 = measure(trig4, echo4);
  Serial.print("Distancia 1 ");
  Serial.println (dist1);
  Serial.print("Distancia 2 ");
  Serial.println (dist2);
  Serial.print("Distancia 3 ");
  Serial.println (dist3);
  Serial.print("Distancia 4 ");
  Serial.println (dist4);

  // Intensidad es inv. prop. a la distancia
  inten1 = 100 - dist1;
  inten2 = 100 - dist2;
  inten3 = 100 - dist3;
  inten4 = 100 - dist4;

 // Si la distancia es menor o igual a 20 cm en un sensor, vibrar con la intensidad en ese sensor.
  if (dist1 <= 5){
  digitalWrite(motorPin1, inten1);
  delay (100);
  digitalWrite (motorPin1, LOW);
 
  }
  if (dist2 <= 5){
  digitalWrite(motorPin1, inten1);
  delay (100);
  digitalWrite (motorPin1, LOW);
  }
  if (dist3 <= 5){
  digitalWrite(motorPin1, inten1);
  delay (100);
  digitalWrite (motorPin1, LOW);
  }
  if (dist4 <= 5){
  digitalWrite(motorPin1, inten1);
  delay (100);
  digitalWrite (motorPin1, LOW);
  }
}
