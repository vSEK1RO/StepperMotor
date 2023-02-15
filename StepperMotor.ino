#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

#define ENA 44
#define IN1 40
#define IN2 42
#define ENB 45
#define IN3 41
#define IN4 43
#define ACW 36
#define STP 37
#define CCW 38
#define SPD A8
#define FRC 39

boolean ACW_STATE = false;
boolean CCW_STATE = false;
boolean STP_STATE = false;
boolean FRC_STATE = false;

byte CurrPosit = 11;
int CurrSpeed = 0;
int ItervSpeed = 0;
int MAXSPEED = 0; 

int ALLPosit[13];

void setup() {

lcd.init();
  
ALLPosit[0]  = B00000000;
ALLPosit[1]  = B11000000;
ALLPosit[2]  = B00011000;
ALLPosit[3]  = B10100000;
ALLPosit[4]  = B00010100;
ALLPosit[5]  = B11000000;
ALLPosit[6]  = B00011000;
ALLPosit[7]  = B10100000;
ALLPosit[8]  = B00010100;
ALLPosit[9]  = B11000000;
ALLPosit[10] = B00011000;
ALLPosit[11] = B10100000;
ALLPosit[12] = B00010100;

pinMode(ENA,OUTPUT);
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(ENB,OUTPUT);
pinMode(IN3,OUTPUT);
pinMode(IN4,OUTPUT);
pinMode (ACW,INPUT_PULLUP);
pinMode (STP,INPUT_PULLUP);
pinMode (CCW,INPUT_PULLUP);
pinMode (FRC,INPUT_PULLUP);
clockwise();
}

void clockwise()
{
CurrPosit = CurrPosit + 1;
if (CurrPosit == 13) CurrPosit = 1;
stepmotor();
}

void anticlockwise()
{
CurrPosit = CurrPosit - 1;
if (CurrPosit == 0) CurrPosit = 12;
stepmotor();
}

void stepmotor()
{
digitalWrite(ENA,0);
digitalWrite(ENB,0);
digitalWrite(IN1,bitRead(ALLPosit[CurrPosit],6));
digitalWrite(IN2,bitRead(ALLPosit[CurrPosit],5));
digitalWrite(IN3,bitRead(ALLPosit[CurrPosit],3));
digitalWrite(IN4,bitRead(ALLPosit[CurrPosit],2));
digitalWrite(ENA,bitRead(ALLPosit[CurrPosit],7));
digitalWrite(ENB,bitRead(ALLPosit[CurrPosit],4));
}

void superFRC()
{
label:  
MAXSPEED = map(analogRead(SPD), 0, 1023, 10000, 1000);
delayMicroseconds(MAXSPEED);
if  (ACW_STATE) clockwise();
if  (CCW_STATE) anticlockwise();
if (digitalRead(STP)) goto label;
}  

void loop() {

lcd.clear();
int a = analogRead(SPD);
if (!FRC_STATE) CurrSpeed = map(a, 0, 1023, 1, 250); else CurrSpeed = map(a, 0, 1023, 5010, 250); 

ItervSpeed = int (60000/12/CurrSpeed);

if (!ACW_STATE) ACW_STATE = !digitalRead(ACW);
if (!CCW_STATE) CCW_STATE = !digitalRead(CCW);
if (!FRC_STATE) FRC_STATE = !digitalRead(FRC);
STP_STATE = !digitalRead(STP);
if (STP_STATE) {
ACW_STATE = 0;
CCW_STATE = 0;
FRC_STATE = 0;
}

if  (ACW_STATE) clockwise();
if  (CCW_STATE) anticlockwise();

if (ItervSpeed != 0) {
lcd.setCursor(0,1);
lcd.print(CurrSpeed);    
lcd.print("ob/min ");
lcd.print(ItervSpeed);
lcd.print("mS");
lcd.setCursor(4, 0);
lcd.print(ACW_STATE);
lcd.print(STP_STATE);
lcd.print(CCW_STATE);
lcd.print(" M");
lcd.print(MAXSPEED);      
lcd.setCursor(15, 0);
lcd.print(FRC_STATE);
lcd.setCursor(0,0);
lcd.print(CurrPosit*30);
if (ACW_STATE || CCW_STATE) delay(ItervSpeed); else delay(125);
} else superFRC();
}
