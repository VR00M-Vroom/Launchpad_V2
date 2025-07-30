#include <Arduino.h>
//Button pins
 const int BUT1 = D5;
 const int BUT2 = D6;
 const int BUT3 = D7;
 const int BUT4 = D8;

 //Led pins
 const int LED1 = D0;
 const int LED2 = D1;
 const int LED3 = D2;
 const int LED5 = D3;
 
//debounce times
    unsigned long lastDebounceTime1 = 0;
    unsigned long lastDebounceTime2 = 0;
    unsigned long lastDebounceTime3 = 0;
    unsigned long lastDebounceTime4 = 0;  
    const unsigned long debounceDelay = 50; 
    
//patterns
bool pattern1true = false;
bool pattern2true = false;
bool isActive = true;

//buttonStates
int lastButtonState1 = HIGH;
int lastButtonState2 = HIGH;
int lastButtonState3 = HIGH;
int lastButtonState4 = HIGH;


void setup() {
    pinMode(BUT1, INPUT_PULLUP);
    pinMode(BUT2, INPUT_PULLUP);
    pinMode(BUT3, INPUT_PULLUP);
    pinMode(BUT4, INPUT_PULLUP);
    pinMode(LED1, OUTPUT);
    pinMode(LED2, OUTPUT);
    pinMode(LED3, OUTPUT);
    pinMode(LED5, OUTPUT);

    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED5, LOW);

}
void loop() {



if(!isActive) {
 allLedsOFF();
 return;
}
    
if(pattern1true) {
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED3, LOW);
 digitalWrite(LED5, LOW);
 delay(100);
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, HIGH);
 digitalWrite(LED5, HIGH);


} else if(pattern2true) {
 digitalWrite(LED1, LOW);
 digitalWrite(LED2, HIGH);
 digitalWrite(LED3, LOW);
 digitalWrite(LED5, HIGH);
 delay(100);
 digitalWrite(LED1, HIGH);
 digitalWrite(LED2, LOW);
 digitalWrite(LED3, HIGH);
 digitalWrite(LED5, LOW);

} else {
    allLedsOFF();
}
//   
int reading1 = digitalRead(BUT1);
    if (reading1 != lastButtonState1) {
        lastDebounceTime1 = millis();
    }

    if ((millis() - lastDebounceTime1) > debounceDelay) {
        if (reading1 == LOW && lastButtonState1 == HIGH) {  
            pattern1true = !pattern1true;
            pattern2true = false;  
        }
    }
   lastButtonState1 = reading1 ;

//
int reading2 = digitalRead(BUT2);
    if (reading2 != lastButtonState2) {
        lastDebounceTime2 = millis();
    }

    if ((millis() - lastDebounceTime2) > debounceDelay) {
        if (reading2 == LOW && lastButtonState2 == HIGH) {  
            pattern2true = !pattern2true;
            pattern1true = false;  
        }
    }
    lastButtonState2 = reading2 ;

//
    int reading3 = digitalRead(BUT3);
    if (reading3 != lastButtonState3) {
        lastDebounceTime3 = millis();
    }

    if ((millis() - lastDebounceTime3) > debounceDelay) {
        if (reading2 == LOW && lastButtonState3 == HIGH) {  
            isActive = true;
        }
    }
    lastButtonState3 = reading3 ;
    
//
     int reading4 = digitalRead(BUT4);
    if (reading4 != lastButtonState4) {
        lastDebounceTime4 = millis();
    }

    if ((millis() - lastDebounceTime4) > debounceDelay) {
        if (reading4 == LOW && lastButtonState4 == HIGH) {  
            isActive = true;
        }
    }
    lastButtonState4 = reading4 ;
} 
    
    
void allLedsON() {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED5, HIGH);
}

void allLedsOFF() {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED5, LOW);
}


 