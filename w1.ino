#include <SevSeg.h>
#include <Keypad.h>
SevSeg sevseg; 
#define Do 523
#define Re 587
#define Mi 659
#define Fa 698
#define So 784
#define La 880
#define Si 988
#define Do2 1046
#define Re2 1175
#define Re22 1247
#define Mi2 1318
#define Fa2 1397
#define So2 1568
#define La2 1760
#define La22 1865
#define Si2 1976
#define Do3 2092



const byte ROWS = 4;
const byte COLS = 4;
char key;


int SW[]={493,523,587,659,698,784,880,988,1046,1175,1318,1397,1568,1760,1976,2092};

char keys[ROWS][COLS]={
   {'7', '4', '1', '0'},
  {'8','5' , '2', 'A'},
  {'9', '6', '3', 'B'},
  {'C', 'D', 'E', 'F'}
};
int k;  //                                 /                         /                           /                                 /

char *mos[]={
  ".-" ,"-..." , "-.-." , "-.." , "." , "..-." , "--." , "...." , "..",     
  ".---" , "-.-" , ".-.." , "--" , "-." , "---" , ".--." , "--.-" , ".-." ,
  "..." , "-" , "..-" , "...-" , ".--" , "-..-" , "-.--" , "--.."
  };
char *son;

byte rowPins[ROWS]={2,3,4,5};
byte colPins[COLS]={6,7,8,9};
Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);

void setup() {
   Serial.begin(9600);
  pinMode(12,OUTPUT);

}
void loop() {
char s;
String ss;
int num,i;
if(Serial.available())
 {
  s = Serial.read();
  if(s >='A' && s <='Z')
    {
      num = s -'A';
      son = mos[num];
      while(*son!='\0')
      {
        if(*son=='.')
         {
            tone(12,440,100)  ;
            delay(100);
          }
       else
       {
            tone(12,440,300);
            delay(300);
        }
        son++;
        delay(100);
      }//while
      delay(300);  //字母間隔
      
      
      }//小IF
  if(s == ' ')
  {
    delay(700);
    }
  

  
  }
   

}
