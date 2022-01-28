// VARIABLES
int trig1 = 9;
int echo1 = 8;
int trig2 = 7;
int echo2 = 6;
int motorPin1 = 10;
int motorPin2 = 11;
int counter = 0;
int dist1, dist2, inten1, inten2;

// SETUP
void setup()
{
  Serial.begin (9600);

//Definir los O e I
  pinMode (trig1, OUTPUT);
  pinMode (echo1, INPUT);
  pinMode (trig2, OUTPUT);
  pinMode (echo2, INPUT);

//Activar los sensores de proximidad.
  digitalWrite (trig1, LOW);
  digitalWrite (trig2, LOW);

// Definir los O e I de los motores
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

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
  Serial.print("Distancia1 ");
  Serial.println (dist1);
  Serial.print("Distancia2 ");
  Serial.println (dist2);

  // Intensidad es inv. prop. a la distancia
  inten1 = 100 - dist1;
  inten2 = 100 - dist2;

  // Imprimir los datos en el monitor serial.
  Serial.println(inten1);
  Serial.println(inten2);
  Serial.println("___________________________________________");


 // Si la distancia es menor o igual a 150 mm en un sensor, vibrar con la intensidad en ese sensor.
  if (dist1 <= 100){
    // Vibrar
  analogWrite(motorPin1, inten1);
  }
  if (dist2 <= 100){
  analogWrite(motorPin2, inten2);
  }
}
