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

int dist1, inten1, dist2, inten2, dist3, inten3, dist4, inten4;

// SETUP
void setup()
{
  Serial.begin (9600);

// Decir que los pines de los sensores serán output para los triggers e input para los echoes.
  pinMode (trig1, OUTPUT);
  pinMode (echo1, INPUT);
  pinMode (trig2, OUTPUT);
  pinMode (echo2, INPUT);
  pinMode (trig3, OUTPUT);
  pinMode (echo3, INPUT);
  pinMode (trig4, OUTPUT);
  pinMode (echo4, INPUT);
  
//Apagar los triggers de todos los sensores, supongo que por buena practica.
  digitalWrite (trig1, LOW);
  digitalWrite (trig2, LOW);
  digitalWrite (trig3, LOW);
  digitalWrite (trig4, LOW);

// Decir que los pines de los motores serán output. 
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);

// Vibracion de bienvenida
  analogWrite(motorPin1, 225);
  analogWrite(motorPin2, 225);
  analogWrite(motorPin3, 225);
  analogWrite(motorPin4, 225);
  delay(100);
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  delay(100);
  analogWrite(motorPin1, 225);
  analogWrite(motorPin2, 225);
  analogWrite(motorPin3, 225);
  analogWrite(motorPin4, 225);
  delay(100);
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);
  delay(100);  
}

// Funcion MEASURE
int measure1 (int trig1, int echo1)
{
  int tiempo;
  digitalWrite (trig1, HIGH);
  delay (100);
  digitalWrite (trig1, LOW);
  tiempo = pulseIn (echo1, HIGH);
  return tiempo / 58;
}

int measure2 (int trig1, int echo1)
{
  int tiempo;
  digitalWrite (trig2, HIGH);
  delay (100);
  digitalWrite (trig2, LOW);
  tiempo = pulseIn (echo2, HIGH);
  return tiempo / 58;
}

int measure3 (int trig3, int echo3)
{
  int tiempo;
  digitalWrite (trig3, HIGH);
  delay (100);
  digitalWrite (trig3, LOW);
  tiempo = pulseIn (echo3, HIGH);
  return tiempo / 58;
}

int measure4 (int trig4, int echo4)
{
  int tiempo;
  digitalWrite (trig4, HIGH);
  delay (100);
  digitalWrite (trig4, LOW);
  tiempo = pulseIn (echo4, HIGH);
  return tiempo / 58;
}

// LOOP
void loop()
{
  // Medidas de distancias de los sensores 1 y 2
  dist1 = measure1(trig1, echo1);
  dist2 = measure2(trig2, echo2);
  dist3 = measure3(trig3, echo3);
  dist4 = measure4(trig4, echo4);
  Serial.print("Distancia 1 ");
  Serial.println (dist1);
  Serial.print("Distancia 2 ");
  Serial.println (dist2);
  Serial.print("Distancia 3 ");
  Serial.println (dist3);
  Serial.print("Distancia 4 ");
  Serial.println (dist4);
  Serial.println ("_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _");

  // Imprimir los datos en el monitor serial.
  Serial.print("Intensidad 1");
  Serial.println(inten1);
  Serial.print("Intensidad 2");
  Serial.println(inten2);
  Serial.print("Intensidad 3");
  Serial.println(inten3);
  Serial.print("Intensidad 4");
  Serial.println(inten4);
  Serial.println("___________________________________________");


 // Si la distancia es menor o igual a 150 mm en un sensor, vibrar con la intensidad en ese sensor.
  while (dist1 <= 100){
  digitalWrite(motorPin1, 225);
  }
  while (dist2 <= 100){
  digitalWrite(motorPin2, 225);
  }
  while (dist3 <= 100){
  digitalWrite(motorPin3, 225);
  }
  while (dist4 <= 100){
  digitalWrite(motorPin4, 225);
  }
}
