// Levels of water
const int levelEmpty = 0;
const int levelMedium = 400;
const int levelFull = 700;

// Leds
int ledRed = 4;
int ledYellow = 3;
int ledGreen = 2;

// Relé
int rele = 13;

void setup() {
  Serial.begin(9600);
  pinMode(ledRed, OUTPUT);
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void loop(){
  Serial.print("Water level sensor value: "); 
  int level = analogRead(A0);
  Serial.println(level);
  delay(500);

  if((level >= levelEmpty) && (level < levelMedium)){
    digitalWrite(ledRed, HIGH);
    digitalWrite(rele, HIGH);
    
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, LOW);        
    }else if((level >= levelMedium) && (level < levelFull)){
    digitalWrite(ledRed, LOW);
    
    digitalWrite(ledYellow, HIGH);
    digitalWrite(rele, HIGH);
    digitalWrite(ledGreen, LOW);   
  } else if(level >= levelFull){
    digitalWrite(ledRed, LOW);
    
    digitalWrite(ledYellow, LOW);
    digitalWrite(ledGreen, HIGH);
    digitalWrite(rele, LOW);
  }  
}

