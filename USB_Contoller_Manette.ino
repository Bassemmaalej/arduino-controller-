const int button_1 = 8;  

const int button_2 = 9; 

const int button_3= 10;  

const int button_4= 11;  


int button1 = LOW;
int button2 = LOW;
int button3 = LOW;
int button4 = LOW;
char BYTE;

#define VRX_PIN  A0
#define VRY_PIN  A1 
#define LEFT_THRESHOLD  400
#define RIGHT_THRESHOLD 800
#define UP_THRESHOLD    400
#define DOWN_THRESHOLD  800

#define COMMAND_NO     0x00
#define COMMAND_LEFT   0x01
#define COMMAND_RIGHT  0x02
#define COMMAND_UP     0x04
#define COMMAND_DOWN   0x08

int xValue = 0 ; 
int yValue = 0 ; 
int command = COMMAND_NO;

void setup() {
// This To Declare the Input And Output
  Serial.begin(9600) ;
 
  pinMode(button_1, INPUT);

  pinMode(button_2, INPUT);

  pinMode(button_3, INPUT);
  
  pinMode(button_4, INPUT);
}

void loop() {

   button1 = digitalRead(button_1);
   button2 = digitalRead(button_2);
   button3 = digitalRead(button_3);
   button4 = digitalRead(button_4);

  
  xValue = analogRead(VRX_PIN);
  yValue = analogRead(VRY_PIN);

  
  command = COMMAND_NO;

  
  if (xValue < LEFT_THRESHOLD)
    command = command | COMMAND_LEFT;
  else if (xValue > RIGHT_THRESHOLD)
    command = command | COMMAND_RIGHT;


  if (yValue < UP_THRESHOLD)
    command = command | COMMAND_UP;
  else if (yValue > DOWN_THRESHOLD)
    command = command | COMMAND_DOWN;

  //This for Contrôle Action Of The Player
 if (button1 == HIGH) {

    Serial.write(1);
   
  } else {
    
    Serial.write(0);

  }

  if (button2 == HIGH) {

    Serial.write(2);
   
  } else {
    
    Serial.write(0);

  }

if (button3 == HIGH) {

    Serial.write(3);
   
  } else {
    
    Serial.write(0);

  }

if (button4 == HIGH) {

    Serial.write(4);
   
  } else {
    
    Serial.write(0);

  }

  
  // this For The Contrôle Position 
  if (command & COMMAND_LEFT) {
    Serial.println("COMMAND LEFT");
    Serial.write(1);
  }

  if (command & COMMAND_RIGHT) {
    Serial.println("COMMAND RIGHT");
    Serial.write(2);
  }

  if (command & COMMAND_UP) {
    Serial.println("COMMAND UP");
    Serial.write(3);
  }

  if (command & COMMAND_DOWN) {
    Serial.println("COMMAND DOWN");
    Serial.write(4);
  }

 
}
