#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal.h>
//#define DEBUG
#ifndef DEBUG
#define MOTOR_A 0+
#define MOTOR_B 1
#define ROTATION_DELAY 2000//2000mS
#endif
#define PIR_1 A0
#define PIR_2 A1
const int C0 = A2, C1 = A3, C2 = 13, C3 = 6;//ROWS
const int R0 = 5, R1 = 4, R2 = 3, R3 = 2;//COLS
String PASSWORD = "4926";
int Camera_ActionState = 0;
LiquidCrystal lcd (7, 8, 9, 10, 11, 12);
void RTC_ManageFun(void)
{
}
void Delay(int a)
{
  int j;
 int i;
  for (i = 0; i < a; i++)
  {
    for (j = 0; j < 100; j++)
    {
    }
  }
}
void Password_Check(void)
{
  boolean flag = 1, VerifyPSW_Flag = 0;
  char buff[17], char_count = 0, PassWord[4],ch=0;
  memset(buff, '\0', sizeof(buff));
  memset(PassWord, '\0', sizeof(PassWord));
  sprintf(buff, "                ");
  while (flag)
  {
    lcd.setCursor(0, 0);
    lcd.print(" Enter Password ");
    lcd.setCursor(0, 1);
    lcd.print(buff);
    if (VerifyPSW_Flag)
    {
      delay(2000);
      PassWord[char_count] = '\0';
      String passwordVal = String(PassWord);
      if (passwordVal.indexOf(PASSWORD))
      {
//        Camera_ActionState != Camera_ActionState;
//        Serial.println(Camera_ActionState);
        if (Camera_ActionState ==0)
        {
          Camera_ActionState = 1;
          lcd.setCursor(0, 0);
          lcd.print("   ACTIVATED    ");
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
        else
        {
          Camera_ActionState = 0;
          lcd.setCursor(0, 0);
          lcd.print("   DEACTIVATED  ");
          lcd.setCursor(0, 1);
           lcd.print("                ");  
        }
      }
      else
      {
        lcd.setCursor(0, 0);
        lcd.print(" Wrong Password ");
        lcd.setCursor(0, 1);
        lcd.print("                ");
      }
      delay(2000);
      break;
 }
    if ((ch = Read_Keypad()) = 0)
    {
      if (isdigit(ch))
      {
        if ( char_count <= 3 )
        {
          PassWord[char_count] = ch;
switch (char_count)
          {
            case 0: sprintf(buff, "   X            ");
              break;
            case 1: sprintf(buff, "   X X          ");
              break;
            case 2: sprintf(buff, "   X X X        ");
              break;
            case 3: sprintf(buff, "   X X X X      ");
              break;
          }
++char_count;
//Serial.println(PassWord);
          if (char_count >= 4)
            VerifyPSW_Flag = 1;
        }
      }
      else
      {
        if (ch == '*')
          break;
      }
    }
  }
}

//------------------------------- // Key Scan Function //-------------------------------

char Read_Keypad(void)
{

  //  KEY_PAD = 0X7F;
  digitalWrite(R0, HIGH);//0
  digitalWrite(R1, HIGH);//1
  digitalWrite(R2, HIGH);//2
  digitalWrite(R3, HIGH);//3
  digitalWrite(C0, HIGH);//4
  digitalWrite(C1, HIGH);//5
  digitalWrite(C2, HIGH);//6
  digitalWrite(C3, LOW);//7

  if ((digitalRead(R3)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R3)) == LOW);
    return 'D';
  }

  if ((digitalRead(R2)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R2)) == LOW);
    return 'C';
  }
 if ((digitalRead(R1)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R1)) == LOW);
    return 'B';
  }

  if ((digitalRead(R0)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R0)) == LOW);
    return 'A';
  }
  //
  //
  //  KEY_PAD = 0XBF;
  digitalWrite(R0, HIGH);//0
  digitalWrite(R1, HIGH);//1
  digitalWrite(R2, HIGH);//2
  digitalWrite(R3, HIGH);//3
  digitalWrite(C0, HIGH);//4
  digitalWrite(C1, HIGH);//5
  digitalWrite(C2, LOW);//6
  digitalWrite(C3, HIGH);//7
  if ((digitalRead(R3)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R3)) == LOW);
     }  if ((digitalRead(R2)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R2)) == LOW);
     }
  if ((digitalRead(R1)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R1)) == LOW);
   
  }
  if ((digitalRead(R0)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R0)) == LOW);
   
  }
  //
  //
  //  KEY_PAD = 0XDF;
  digitalWrite(R0, HIGH);//0
  digitalWrite(R1, HIGH);//1
  digitalWrite(R2, HIGH);//2
  digitalWrite(R3, HIGH);//3
  digitalWrite(C0, HIGH);//4
  digitalWrite(C1, LOW);//5
  digitalWrite(C2, HIGH);//6
  digitalWrite(C3, HIGH);//7

  if ((digitalRead(R3)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R3)) == LOW);
     }
  if ((digitalRead(R2)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R2)) == LOW);
     }
  if ((digitalRead(R1)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R1)) == LOW);
     }
  if ((digitalRead(R0)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R0)) == LOW);
     }
  //
  //
  //  KEY_PAD = 0XEF;
  digitalWrite(R0, HIGH);//0
  digitalWrite(R1, HIGH);//1
  digitalWrite(R2, HIGH);//2
  digitalWrite(R3, HIGH);//3
  digitalWrite(C0, LOW);//4
  digitalWrite(C1, HIGH);//5
  digitalWrite(C2, HIGH);//6
  digitalWrite(C3, HIGH);//7
  if ((digitalRead(R3)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R3)) == LOW);
     }
  if ((digitalRead(R2)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R2)) == LOW);
     }
  if ((digitalRead(R1)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R1)) == LOW);
     }
  if ((digitalRead(R0)) == LOW)
  {
    Delay(100);
    while ((digitalRead(R0)) == LOW);
     }
  return 0;
}
/*void MotorRotateLeft(void)
{
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, LOW);
  delay(2000);
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, HIGH);
}
void MotorRotateRight(void)
{
  digitalWrite(MOTOR_B, HIGH);
  digitalWrite(MOTOR_A, LOW);
  delay(2000);
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, HIGH);
}

void Check_PIR(void)
{
  if (digitalRead(PIR_1))
  {
    MotorRotateLeft();
  }
  else if (digitalRead(PIR_2))
  {
    MotorRotateRight();
  }
}*/
void MotorRotateLeft(void)
{
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, LOW);
  delay(ROTATION_DELAY);
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, HIGH);
}

void MotorRotateRight(void)
{
  digitalWrite(MOTOR_B, HIGH);
  digitalWrite(MOTOR_A, LOW);
  delay(ROTATION_DELAY);
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, HIGH);
}

int LeftRotationFlag = 0, RightRotationFlag = 0;
void Check_PIR(void)
{
  if (digitalRead(PIR_1))
  {
    if (!LeftRotationFlag)
    {
      LeftRotationFlag = 1;
      MotorRotateLeft();
    }
  }
  else if (digitalRead(PIR_2))
  {
    if (!RightRotationFlag)
    {
      RightRotationFlag = 1;
      MotorRotateRight();
    }

  }
  else
  {
    if (LeftRotationFlag)
    {
      LeftRotationFlag = 0;
      MotorRotateRight();
    }
    if (RightRotationFlag)
    {
      RightRotationFlag = 0;
      MotorRotateLeft();
    }
  }
}

void setup ()
 {
#ifdef DEBUG
  Serial.begin(9600);
#else
  pinMode(MOTOR_A, OUTPUT);
  pinMode(MOTOR_B, OUTPUT);
  digitalWrite(MOTOR_A, HIGH);
  digitalWrite(MOTOR_B, HIGH);

#endif
  lcd.begin(16, 2);
  pinMode(R0, INPUT_PULLUP);
  pinMode(R1, INPUT_PULLUP);
  pinMode(R2, INPUT_PULLUP);
  pinMode(R3, INPUT_PULLUP);
  pinMode(C0, OUTPUT);
  pinMode(C1, OUTPUT);
  pinMode(C2, OUTPUT);
  pinMode(C3, OUTPUT);
  pinMode(PIR_1, INPUT);
  pinMode(PIR_2, INPUT);
  Wire.begin();
  RTC.begin();
  if (! RTC.isrunning()) {
#ifdef DEBUG
    Serial.println("RTC is NOT running!");
#endi   
  }
}

void loop () {
  RTC_ManageFun();
  if (0 != Read_Keypad())
    Password_Check();
  if (Camera_ActionState)
    Check_PIR();
  //delay(1000);
}
