//*
//auther: Abdullah Al Masum        Date: 21 June,2021 
//*

// defines pins numbers
const int trigPin1 = 2;       //defining echo sensor pins  1
const int echoPin1 = 3;
const int trigPin2 = 4;      //defining echo sensor pins 2
const int echoPin2 = 5;
const int trigPin3 = 6;      //defining echo sensor pins 3
const int echoPin3 = 7;
const int trigPin4 = 8;      //defining echo sensor  pins 4
const int echoPin4 = 9;
const int buttonPin1 = 10;   // defining push_btn1 pin 
const int buttonPin2 = 11;   // defining push_btn1 pin
const int ledLight = 12;     // defining LED Pin
const int buzzerPin= 13;     // defining Buzzer pin

// defines variables
long duration1;           //defining echo sensor varables 1
int distance1;
long duration2;           //defining echo sensor varables 2
int distance2;
long duration3;           //defining echo sensor varables 3
int distance3;
long duration4;           //defining echo sensor varables 4
int distance4;
int buttonState1,buttonState2;

void setup() {
      pinMode(buzzerPin, OUTPUT);
      pinMode(trigPin1, OUTPUT);   // Sets the trigPin as an Output 1
      pinMode(echoPin1, INPUT);    // Sets the echoPin as an Input  1
      pinMode(trigPin2, OUTPUT);   // Sets the trigPin as an Output 2
      pinMode(echoPin2, INPUT);    // Sets the echoPin as an Input  2
      pinMode(trigPin3, OUTPUT);   // Sets the trigPin as an Output 3
      pinMode(echoPin3, INPUT);    // Sets the echoPin as an Input  3
      pinMode(trigPin4, OUTPUT);   // Sets the trigPin as an Output 4
      pinMode(echoPin4, INPUT);    // Sets the echoPin as an Input  4

      // initialize the pushbutton pin as an input:
      pinMode(buttonPin1, INPUT);
      pinMode(buttonPin2, INPUT);
      // Starts the serial communication
      Serial.begin(9600);   // setting the braud rate       
}

void loop() {
    buttonState1 = digitalRead(buttonPin1);
    buttonState2 = digitalRead(buttonPin2);
    
    if(buttonState1 == HIGH && buttonState2 == HIGH){  
        buzzbuzz(120); // 120 cm
    }else if(buttonState1 == HIGH && buttonState2 == LOW){
        buzzbuzz(90);  // 90 cm
    }
    else if(buttonState1 == LOW && buttonState2 == HIGH){
        buzzbuzz(60);  // 60 cm
    }
    else{
        buzzbuzz(30);  // 30 cm  Default
    }
}

void buzzbuzz(int safeDistance){
      // Clears the trigPin
      digitalWrite(trigPin1, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin1, HIGH);      // Sets the trigPin on HIGH state for 10 micro seconds
      delayMicroseconds(10);
      digitalWrite(trigPin1, LOW);
      duration1 = pulseIn(echoPin1, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
      distance1= duration1*0.034/2;       // Calculating the distance. Here,multiplying (0.034/2) is for calibrating
      
      digitalWrite(trigPin2, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin2, HIGH);      // Sets the trigPin on HIGH state for 10 micro seconds
      delayMicroseconds(10);
      digitalWrite(trigPin2, LOW);
      duration2 = pulseIn(echoPin2, HIGH);// Reads the echoPin, returns the sound wave travel time in microseconds
      distance2= duration2*0.034/2;       // Calculating the distance. Here,multiplying (0.034/2) is for calibrating
      
      digitalWrite(trigPin3, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin3, HIGH);       // Sets the trigPin on HIGH state for 10 micro seconds
      delayMicroseconds(10);
      digitalWrite(trigPin3, LOW);
      duration3 = pulseIn(echoPin3, HIGH); // Reads the echoPin, returns the sound wave travel time in microseconds
      distance3= duration3*0.034/2;        // Calculating the distance. Here,multiplying (0.034/2) is for calibrating
      
      digitalWrite(trigPin4, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin4, HIGH);       // Sets the trigPin on HIGH state for 10 micro seconds
      delayMicroseconds(10);
      digitalWrite(trigPin4, LOW);
      duration4 = pulseIn(echoPin4, HIGH);   // Reads the echoPin, returns the sound wave travel time in microseconds
      distance4= duration4*0.034/2;          // Calculating the distance. Here,multiplying (0.034/2) is for calibrating
      
      if ( distance1 <= safeDistance || distance2 <= safeDistance || distance3 <= safeDistance || distance4 <= safeDistance)
      {                           
          // turn BUZZER on and RED LIGHT on
          digitalWrite(buzzerPin, HIGH);
          digitalWrite(ledLight, HIGH);
      } else {
          // turn buzzer off and RED LIGHT off:
          digitalWrite(buzzerPin, LOW);
          digitalWrite(ledLight, LOW);
       }
      
      // Prints the distance on the Serial Monitor
      // This part can be omitted
      Serial.print("Distance1:  " );
      Serial.print(distance1);
      Serial.print("\t Distance2: ");
      Serial.print(distance2);
      Serial.print("\t Distance3:  " );
      Serial.print(distance3);
      Serial.print("\t Distance4: ");
      Serial.print(distance4);
      Serial.println();
      delay(500);
}
