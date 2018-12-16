//ultrasonic
#define echoPin1 11 //num of digital pin connected to echo input
#define trigPin1 12 //num of digital pin connected to trigger output
#define LEDPin 13 //enables LED feedback for testing

int maxRange = 30; //max distance observed from sensor
int minRange = 0;
long duration1, distance1; //duration used to calculate distance

//button
const int buttonPin = 3; //push button
const int buttonPin2 = 2;
const int ledPin = 13; // uno board led pin

int buttonState = 0; //curent state of button
int buttonState2 = 0;
int lastButtonState = 0; //previous button state
int lastButtonState2 = 0;
int val = 100; //random number to be sent
int val2 = 200;

 void setup(){
  pinMode(buttonPin, INPUT);
  Serial.begin(9600); //starts serial communication via USB
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(LEDPin, OUTPUT); //board LED for testing 
 }

  void loop(){
digitalWrite(trigPin1, LOW);
delayMicroseconds(2); //pulse off

digitalWrite(trigPin1, HIGH);
delayMicroseconds(10); //pulse for 10 microseconds

digitalWrite(trigPin1, LOW);
duration1 = pulseIn(echoPin1, HIGH); //echo pin listens/receives

//from that data calculate distance in cm based on speed of sound
  distance1 = duration1/58.2;

//error handling
if (distance1 >= maxRange || distance1 <= minRange){
  //Serial.println("-1"); //if nothing observed output -1
  digitalWrite(LEDPin, HIGH);  //LED will be on
}else{
  Serial.println(distance1); //prints the distance in CM
  digitalWrite(LEDPin, LOW); //LED will be off if object is detected
}
 delay(50); // good practice to not overload the serial port


//button
 buttonState = digitalRead(buttonPin);
  
  if (buttonState != lastButtonState) {    //compare the buttonstate against previous  
    if(buttonState == 1){                  //if the state has changed, nothing - so serial value isn't updated
    }else{
      Serial.println(val);    
    }
    //in case of bounce
    delay(50);
  }
  //save current state as last state, for next time through loop
  lastButtonState = buttonState;


  buttonState2 = digitalRead(buttonPin2);
     if (buttonState2 != lastButtonState2){
      if (buttonState2 == 1){ 
    }else{
     Serial.println(val2);
    }
    delay(50);
     }
     lastButtonState2 = buttonState2;
 }


