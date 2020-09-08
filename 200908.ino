int i;
void setup() {
  // put your setup code here, to run once:
for(i=2; i<6; i++)
  pinMode(i, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=2; i<6; i++)
  digitalWrite(i, HIGH);
  delay(500);
  for(i=2; i<6; i++)
  digitalWrite(i, LOW);
  delay(500);  
}
