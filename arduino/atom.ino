void setup() {
  Serial.begin(9600);
 
  //Set pin 11 to be output pin (connect LED here)
  pinMode(13, OUTPUT);
   pinMode(12, OUTPUT);
    pinMode(11, OUTPUT);
     pinMode(10, OUTPUT);
 
  
  
}
 



 
//this function is called when we get a character
//over USB/Serial
void got_char(char x) {
 
  //if we get l over Serial and so on 
  if(x == 'l') {
    //... blink the LED
    digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  }
  if(x == 'r'){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
    
  }
  if(x == 'b'){
   digitalWrite(13,LOW);
    digitalWrite(12,HIGH);
    digitalWrite(11,HIGH);
    digitalWrite(10,LOW);
  }
  if(x == 'f'){
    digitalWrite(13,HIGH);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,HIGH);
  }
  if(x == 's'){
    digitalWrite(13,LOW);
    digitalWrite(12,LOW);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
  }
}
 
void loop() {
  //check if there's any data available on serial
  if(Serial.available() > 0) {
    //if there is, we read it
    byte byte_read = Serial.read();
 
    //and call "got_char"
    got_char((char)byte_read);
  }
}
