int pir = 12;
int led = 13;
int val = 0;
void setup() {
  pinMode(pir, INPUT); 
  pinMode(led, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  val = digitalRead(pir);
  Serial.println(val);
  if(val == 1) {
    digitalWrite(led, HIGH);
    Serial.println("Detection = true");
  }
  else {
    digitalWrite(led, LOW);
    Serial.println("Detection = false");
  }
}
