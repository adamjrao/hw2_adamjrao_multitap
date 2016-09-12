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
int numpressed; //latest number pressed on the keypad
int lastnumpressed; //the initial number pressed on the keypad
int timespressed; //times the number has been pressed
char letter; //stores letter that needs to be printed
const byte maxtimespressed[9]={
  2,4,4,4,4,4,5,4,5}; //stores maximum number of times any given key can be pressed before looping back
const int wait=500; //time to wait for additional presses to same number
const int preventholddelay=50; //time to wait to prevent cycling through things too quickly
unsigned long basetime = 0; //basetime for while loop
unsigned long pressedtime = 0; //last time a button was pressed
unsigned long elapsed=0; //elapsed time in while loop
bool pressed;
int read1;
int counter=0;
int buttonState;
int lastButtonState = 0;
unsigned long debounceDelay=50;
unsigned long lastDebounceTime=0;

void setup()
{
  pinMode(r1,OUTPUT);
  pinMode(r2,OUTPUT);
  pinMode(r3,OUTPUT);
  pinMode(c1,INPUT_PULLUP);
  pinMode(c2,INPUT_PULLUP);
  pinMode(c3,INPUT_PULLUP);
  Serial.begin(9600);
  digitalWrite(c1,HIGH);
  digitalWrite(c2,HIGH);
  digitalWrite(c3,HIGH);
}
void loop()
{
  
  numpressed=16; //reset numpressed (16 doesn't refer to any button on the keypad)
  if (millis()-pressedtime >1000 && pressed){
      //Serial.println("Output");
      Serial.print''(letter);
      pressedtime = millis();
      pressed = false;
      timespressed = 1;
  }
  if (findpress()){ //look for presses, if one has occurred, identify it and continue
    pressedtime = millis();
    pressed = true;
    if (numpressed==lastnumpressed){ //if it was the same as before,
      if (millis()-basetime < 500) {
        incrementtimespressed(); //increment "timespressed"
        basetime = millis();
        definepress(); //use "numpressed" and "timespressed" to define "letter"
        //Serial.println("Repeat");
        //Serial.println(letter); //print the letter that was defined
        rowshigh(); //return all rows high
      } else {
        timespressed = 1;
        definepress();
        basetime = millis();
        //Serial.println("TimedOut");
        //Serial.println(letter);
      }
    } else { //if the number that was pressed was different than before,
      timespressed=1;
      definepress();
      basetime = millis();
      //Serial.println("Different");
      //Serial.println(letter); //print the letter that was defined
    }
    lastnumpressed = numpressed;      
  }
}

void definepress(){ //uses "numpressed" and "timespressed" to define "letter"
    if (numpressed==1){
    if (timespressed==1){
      letter=' ';
    }
    if (timespressed==2){
      letter='1';
    }
  }  
  if (numpressed==2){
    if (timespressed==1){
      letter='A';
    }
    if (timespressed==2){
      letter='B';
    }
    if (timespressed==3){
      letter='C';
    }
    if (timespressed==4){
      letter='2';
    }
  }
  if (numpressed==2){
    if (timespressed==1){
      letter='A';
    }
    if (timespressed==2){
      letter='B';
    }
    if (timespressed==3){
      letter='C';
    }
    if (timespressed==4){
      letter='2';
    }
  }
  if (numpressed==3){
    if (timespressed==1){
      letter='D';
    }
    if (timespressed==2){
      letter='E';
    }
    if (timespressed==3){
      letter='F';
    }
    if (timespressed==4){
      letter='3';
    }
  }
  if (numpressed==4){
    if (timespressed==1){
      letter='G';
    }
    if (timespressed==2){
      letter='H';
    }
    if (timespressed==3){
      letter='I';
    }
    if (timespressed==4){
      letter='4';
    }
  }
  if (numpressed==5){
    if (timespressed==1){
      letter='J';
    }
    if (timespressed==2){
      letter='K';
    }
    if (timespressed==3){
      letter='L';
    }
    if (timespressed==4){
      letter='5';
    }
  }
  if (numpressed==6){
    if (timespressed==1){
      letter='M';
    }
    if (timespressed==2){
      letter='N';
    }
    if (timespressed==3){
      letter='O';
    }
    if (timespressed==4){
      letter='6';
    }
  }
  if (numpressed==7){
    if (timespressed==1){
      letter='P';
    }
    if (timespressed==2){
      letter='Q';
    }
    if (timespressed==3){
      letter='R';
    }
    if (timespressed==4){
      letter='S';
    }
    if (timespressed==5){
      letter='7';
    }
  }
  if (numpressed==8){
    if (timespressed==1){
      letter='T';
    }
    if (timespressed==2){
      letter='U';
    }
    if (timespressed==3){
      letter='V';
    }
    if (timespressed==4){
      letter='8';
    }
  }
  if (numpressed==9){
    if (timespressed==1){
      letter='W';
    }
    if (timespressed==2){
      letter='X';
    }
    if (timespressed==3){
      letter='Y';
    }
    if (timespressed==4){
      letter='Z';
    }
    if (timespressed==5){
      letter='9';
    }
  }
}


bool findpress() //finds a press to define numpressed, if any press occurs, returns true
{
  bool pressfound=false; //variable for press detection

  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  
  if(colm1==LOW) //if the first column is now low, "1" has been pressed
  {
   numpressed = 1;
   pressfound=true;
   delay(200);
   }
  else
  {

   if(colm2==LOW) //if the second column is now low, "2" has been pressed
   {
    numpressed = 2;
    pressfound=true;
    delay(200);
    }
  else
  {
   if(colm3==LOW) //if the third column is now low, "3" has been pressed
   {
    numpressed = 3;
    pressfound=true;
    delay(200);
    }
  }}

  digitalWrite(r1,HIGH);
  digitalWrite(r2,LOW);
  digitalWrite(r3,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  if(colm1==LOW) //if the first column is now low, "4" has been pressed
  {
    numpressed = 4;
    pressfound=true;
    delay(200);
    }
  else
  {
   if(colm2==LOW) //if the second column is now low, "5" has been pressed
   {
    numpressed = 5;
    pressfound=true;
    delay(200);
    }
  else
  {
   if(colm3==LOW) //if the third column is now low, "6" has been pressed
   {
    numpressed = 6;
    pressfound=true;
    delay(200);
    }
  }}

  digitalWrite(r1,HIGH);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,LOW);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  if(colm1==LOW)  //if the first column is now low, "7" has been pressed
  {
    numpressed = 7;
    pressfound=true;
     delay(200);
     }
  else
  {
   if(colm2==LOW)  //if the second column is now low, "8" has been pressed
   {
    numpressed = 8;
    pressfound=true;
    delay(200);
    }
  else
  {
   if(colm3==LOW)  //if the third column is now low, "9" has been pressed
   {
    numpressed = 9;
    pressfound=true;
    delay(200);
    }
  }}
  rowshigh();
  return pressfound; //function returns true if any press found, otherwise returns false
}
/*
bool debounceCheck(int button){  //Checks a pin for a press taking into account bouncing
  bool buttonpress=false;
  read1=digitalRead(button);
  if (read1 != lastButtonState){
  lastDebounceTime=millis();
  }
  if ((millis()-lastDebounceTime)>debounceDelay) {
    if (read1 != buttonState){
       buttonState= read1;
          if (buttonState== LOW){
             counter=counter+1;
             buttonpress=true;
         }
       }
    }  
  lastButtonState=read1;
  return buttonpress;  
  
}*/

void incrementtimespressed(){ //increment "timespressed" until at max value stored in maxtimespressed for that lastnumpressed, then roll over to 1
  if (timespressed==maxtimespressed[lastnumpressed]){ //if at the maximum,
    timespressed=1; //roll over timespressed to one
  }
  else{ //otherwise,
    timespressed++; //increment timespressed
  }
}

void rowshigh(){ //sets all rows high
  digitalWrite(r1,HIGH); //write all the rows high
  digitalWrite(r2,HIGH); 
  digitalWrite(r3,HIGH);
}
