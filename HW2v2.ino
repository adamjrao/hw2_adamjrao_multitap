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
  1,4,4,4,4,4,5,4,5}; //stores maximum number of times any given key can be pressed before looping back
const int wait=500; //time to wait for additional presses to same number
const int preventholddelay=50; //time to wait to prevent cycling through things too quickly
unsigned long basetime; //basetime for while loop
unsigned long elapsed=0; //elapsed time in while loop

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
  numpressed=16; //reset numpressed (16 doesn't refer to any button on the keypad)
  findpress();
    if (numpressed<10&&numpressed>0){ //if 1,2,3,4,5,6,7,8,9 was pressed (any one of the keys with multiple characters assigned),
      lastnumpressed=numpressed; //record which number was pressed,
      basetime=millis(); //and take a base time for the while loop
      while (elapsed<wait){ //while below the time to wait,
        //Serial.println(findpress());
        if(findpress()){ //look for presses, if one has occurred, identify it and continue
          if (numpressed==lastnumpressed){ //if it was the same as before,
            incrementtimespressed(); //increment "timespressed"
            //lastnumpressed=numpressed;
            //timespressed++;
            //Serial.println("The last number was ");
            //Serial.println(lastnumpressed);
            //Serial.println("The number of times pressed was ");
            //Serial.println(timespressed);
            basetime=basetime+(wait-(wait-elapsed)); //roll up the base time, to allow another wait period until next press of the same button
            definepress(); //use "numpressed" and "timespressed" to define "letter"
            //timespressed=1;
            Serial.println(letter); //print the letter that was defined
            rowshigh(); //return all rows high
            delay(preventholddelay); //delay a little to prevent continuous cycling through "timespressed" during a single press
          }
          else{ //if the number that was pressed was different than before,
            definepress();
            //timespressed=1;
            //disablespacedelay=true; //disable the delay in the space function to allow the press to be detected a second time, at the beginning of void loop
            break; //break out of the while loop
          }
        }
        elapsed=millis()-basetime; //refresh the elapsed time for the while loop
      }
      elapsed=0; //reset the elapsed time for the while loop
      //textstorage(1); //store character
      //dospace(); //do a space
    }
  
  /*findpress();
  if (numpressed<10&&numpressed>0){
    lastnumpressed=numpressed; //record which number was pressed
//    if (findpress()) { //look for presses, if one has occured, identify it and continue
//    lastnumpressed=numpressed;
    if (findpress()){
      if (numpressed==lastnumpressed){
        incrementtimespressed();
        definepress();
      }
    }  
  }*/
}
/*
void definepress(){

      if (lastnumpressed==1) {
      Serial.println("A");
    }
}*/
void definepress(){ //uses "lastnumpressed" and "timespressed" to define "letter"
  if (lastnumpressed==2){
    if (timespressed==1){
      letter='A';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='B';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='C';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='2';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==3){
    if (timespressed==1){
      letter='D';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='E';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='F';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='3';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==4){
    if (timespressed==1){
      letter='G';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='H';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='I';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='4';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==5){
    if (timespressed==1){
      letter='J';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='K';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='L';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='5';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==6){
    if (timespressed==1){
      letter='M';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='N';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='O';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='6';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==7){
    if (timespressed==1){
      letter='P';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='Q';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='R';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='S';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==5){
      letter='7';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==8){
    if (timespressed==1){
      letter='T';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='U';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='V';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='8';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
  if (lastnumpressed==9){
    if (timespressed==1){
      letter='W';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==2){
      letter='X';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==3){
      letter='Y';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==4){
      letter='Z';
      //Serial.println(letter);
      //timespressed=0;
    }
    if (timespressed==5){
      letter='9';
      //Serial.println(letter);
      //timespressed=0;
    }
  }
}

bool findpress() //finds a press to define numpressed, if any press occurs, returns true
{
  bool pressfound=false; //variable for press detection

  digitalWrite(r1,LOW);
  digitalWrite(r2,HIGH);
  digitalWrite(r3,HIGH);
  //digitalWrite(r4,HIGH);
  colm1=digitalRead(c1);
  colm2=digitalRead(c2);
  colm3=digitalRead(c3);
  //colm4=digitalRead(c4);
  if(colm1==LOW) //if the first column is now low, "1" has been pressed
  {
   numpressed = 1;
   pressfound=true;
   //Serial.println("1");
   delay(200);}
  else
  {
   if(colm2==LOW)
   {
    numpressed = 2;
    pressfound=true;
    //Serial.println("2");
    delay(200);}
  else
  {
   if(colm3==LOW)
   {
    numpressed = 3;
    pressfound=true;
    //Serial.println("3");
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
  {
    numpressed = 4;
    pressfound=true;
    //Serial.println("4");
    delay(200);}
  else
  {
   if(colm2==LOW)
   {
    numpressed = 5;
    pressfound=true;
    //Serial.println("5");
    delay(200);}
  else
  {
   if(colm3==LOW)
   {
    numpressed = 6;
    pressfound=true;
    //Serial.println("6");
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
  {
    numpressed = 7;
    pressfound=true;
    //Serial.println("7");
     delay(200);}
  else
  {
   if(colm2==LOW)
   {
    numpressed = 8;
    pressfound=true;
    //Serial.println("8");
       delay(200);}
  else
  {
   if(colm3==LOW)
   {
    numpressed = 9;
    pressfound=true;
    //Serial.println("9");
       delay(200);}
  }}
  rowshigh();
  return pressfound; //function returns true if any press found, otherwise returns false
}
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
  //digitalWrite(r4,HIGH);
}
