
int button = 4; //This goes to the transistor to short out one end of the octocoupleer
int count = 15; //counter is used to determine a buffer time to shutoff the onewheel

void setup() {

  pinMode(button,OUTPUT);
  Serial.begin(9600);
}
void loop() {
  double footpad = analogRead(A6); //defines the pins for the footpad sensors. Must be an analog pin
  double footpad2 = analogRead(A5);

  
  count = count + 1; //add one to the count ever 100ms
  
  if(footpad > 700 and footpad2 >750){ //Change these numbers to adjust sensitivity to turn on the onewheel.
    count = 0;
    state = HIGH;
    digitalWrite(button, HIGH);
    //Serial.print("The OneWheel is ON " ); //These lines are just for debugging
    //Serial.println (footpad );
      } 
     
   if(footpad < 700 or footpad2 < 750){ //Change these numbers to adjust sensitivity to turn off the onewheel. should be same as above
     
     if(count > 6){ //this is where you set the buffer time to turn off the onewheel. basically so if you hit a bump and your foot comes off for a second the machine doesnt turn off
     state = LOW;
     digitalWrite(button, LOW);
     //Serial.print("Onewheel is now Off \n");
     
      }
    } 
  Serial.print ("Count ");
  Serial.println (count );
  
  Serial.print ("footpad " );
  Serial.println (footpad );

  Serial.print ("footpad 2 " );
  Serial.println (footpad2 );
  delay(100);
}
