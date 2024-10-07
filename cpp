const int pingTrigPin=12;
const int pingEchoPin=10;
int buz=5;
void setup()
{
  Serial.begin(9600);
  pinMode(buz,OUTPUT);
  pinMode(pingTrigPin,OUTPUT);
}
void loop()
{
  long duration, cm;
  digitalWrite(pingTrigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(pingTrigPin,HIGH);
  delayMicroseconds(5);
  digitalWrite(pingTrigPin,LOW);
  pinMode(pingEchoPin,INPUT);
  duration=pulseIn(pingEchoPin,HIGH);
  cm=microsecondsToCentimeters(duration);
  if(cm<=50 && cm>0)
  {
    digitalWrite(buz,HIGH);
    delay(100);
    digitalWrite(buz,LOW);
    delay(10);
  }
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(10);
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds /29/2;
}
