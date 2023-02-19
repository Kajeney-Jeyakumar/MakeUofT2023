const int pingPin = 13; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 12; // Echo Pin of Ultrasonic Sensor
const int buzzerPin = 6; // Buzzer pin
const int distanceThreshold = 10;

void setup() {
   Serial.begin(9600); // Starting Serial Terminal
   pinMode(10, OUTPUT); // LED RED
   pinMode(11, OUTPUT); // LED GREEN
   pinMode(9, OUTPUT); // LED BLUE
}

void loop() {
   int duration, inches, cm;
   pinMode(buzzerPin, OUTPUT);
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   cm = microsecondsToCentimeters(duration);

    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    digitalWrite(9, LOW);
    
    if ((cm >= 15)&&(cm <= 20)) {
       Serial.print(duration);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(10, HIGH);
      delay(100);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(10, LOW);
      delay(100);
    }

    else if ((cm < 15)&&(cm >= 10)) {
      Serial.print(duration);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(10, HIGH);
      delay(75);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(10, LOW);
      delay(75);
    }

  else if ((cm < 10)&&(cm >= 5)) {
      Serial.print(duration);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(10, HIGH);
      delay(50);
      digitalWrite(buzzerPin, LOW);
      digitalWrite(10, LOW);
      delay(50);
    }

  
  else if (cm < 5) {
      Serial.print(duration);
      digitalWrite(buzzerPin, HIGH);
      digitalWrite(10, HIGH);
    }

    else {
     digitalWrite(buzzerPin, LOW);
     digitalWrite(10, LOW);
     
     
    }
    //digitalWrite(11, HIGH);

   
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}
