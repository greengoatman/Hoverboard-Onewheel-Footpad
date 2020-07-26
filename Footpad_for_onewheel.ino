
int button = 4;
int count = 15;

void setup() {

  pinMode(button,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  double footpad = analogRead(A6);
  double footpad2 = analogRead(A5);
  int state = LOW;
  
  
  count = count + 1;
  
  if(footpad > 700 and footpad2 >750){
    count = 0;
    state = HIGH;
    digitalWrite(button, HIGH);
    //Serial.print("The OneWheel is ON " );
    //Serial.println (footpad );
      } 
     
   if(footpad < 700 or footpad2 < 750){
     
    
     if(count > 6){
     state = LOW;
     digitalWrite(button, LOW);
     //Serial.print("Onewheel is now Off \n");
     
      }
    } 
  Serial.println (count );
  
  Serial.print ("footpad " );
  Serial.println (footpad );

  Serial.print ("footpad 2 " );
  Serial.println (footpad2 );
  delay(100);
}
