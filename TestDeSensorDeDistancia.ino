int trig = 8;
int echo = 9;

void setup() {
  // Preparar monitor serial
  Serial.begin(9600);

  // 
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  
  // Apagar el trig antes de usarlo. 
  digitalWrite(trig, LOW);
}

int measure(int trig, int echo){
  int tiempo;
  digitalWrite (trig, HIGH);
  delay (100);
  digitalWrite (trig, LOW);
  tiempo = pulseIn (echo, HIGH);
  return tiempo / 58;
}

void loop() {
  Serial.print("Distancia: ");
  Serial.println(measure(trig, echo));
  Serial.println("_____");
}
