// do not use the cloud functions - assume programming through Arduino IDE
#if defined(ARDUINO) 
SYSTEM_MODE(MANUAL); 
#endif

int r1=D0;
int r2=D1;
int r3=D2;
int c1=D3;
int c2=D4;
int c3=D5;
int colm1;
int colm2;
int colm3;


void setup()
{
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  //pinMode(r4,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP);
  //pinMode(c4,INPUT);
  Serial.begin(9600);
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
  //digitalWrite(c4,HIGH);
}
void loop()
{
  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  //digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  //colm4=digitalRead(c4);
  if(colm1==LOW)
  {Serial.println("1");
   delay(200);}
  else
  {
   if(colm2==LOW)
   {Serial.println("2");
    delay(200);}
  else
  {
   if(colm3==LOW)
   {Serial.println("3");
    delay(200);}
  }}

  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  //digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  //colm4=digitalRead(c4);
  if(colm1==LOW)
  {Serial.println("4");
    delay(200);}
  else
  {
   if(colm2==LOW)
   {Serial.println("5");
    delay(200);}
  else
  {
   if(colm3==LOW)
   {Serial.println("6");
    delay(200);}
  }}

  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  //digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  //colm4=digitalRead(c4);
  if(colm1==LOW)
  {Serial.println("7");
     delay(200);}
  else
  {
   if(colm2==LOW)
   {Serial.println("8");
       delay(200);}
  else
  {
   if(colm3==LOW)
   {Serial.println("9");
       delay(200);}
  }}
}
