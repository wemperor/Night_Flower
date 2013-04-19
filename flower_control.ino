
#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 

int pos = 90;    // variable to store the wanted servo position 
int pos_is = 90;  // variable to store the actural servo position

byte light = 90;
 

void setup() 
{ 
 
  Serial.begin(9600);  //serial output for debugging

  pinMode(A2, OUTPUT);
  digitalWrite(A2, HIGH);

  pinMode(10, OUTPUT);

} 


void loop() 

{ 

  pos = (map(analogRead(0),1032,0,160,-64));  //read the light sensor input and map it to some values that make sense
  if (pos < 31) pos = 28;  //borders for opening and closing, adjust to your setup
  if (pos > 129) pos = 135;
  Serial.print(" Actual position: ");
  Serial.print(pos_is);
  Serial.print("  Wanted position: ");
  Serial.println(pos);
  delay(100);

  if (abs(pos-pos_is) > 3){
    if ((pos < pos_is) && (pos_is > 31)) pos_is--;
    if ((pos > pos_is) && (pos_is < 133)) pos_is++;
    myservo.attach(9);
    myservo.write(pos_is  ); 
    delay(50);
    myservo.detach();
    //the trick is, that the servo is only on for about 50ms, this saves energy and makes the movement a bit more natural
  }
  
  if (pos < 80){
     if( light < 250) light += 2;
      }
    else{
      if(light > 0) light--;
    }
  
  analogWrite(11, light);
  Serial.print("LED Value: ");
  Serial.print(light);

} 





