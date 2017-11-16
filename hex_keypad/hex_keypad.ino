int row[]={6,7,8,9};// Defining row pins of keypad connected to Aeduino pins
int col[]={2,3,4,5,6,7,8,9};//Defining column pins of keypad connected to Arduino
int i,j; // Two counter variables to count inside for loop
int col_scan; // Variable to hold value of scanned columns

String code = "";
String correctCode = "DDDD";

int greenLed = 13;
int yellowLed = 12;
int redLed = 11;

void setup()
{
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  
  digitalWrite(yellowLed, HIGH);

  Serial.begin(9600);
  
  Serial.println("To change the code type one, current code is " + correctCode);
  
  for(i=0;i<=3;i++)
  {
    pinMode(row[i],OUTPUT);
    pinMode(col[i],INPUT);
    digitalWrite(col[i],HIGH);
  }
}

void loop()
{ 
  String newCorrectCode = Serial.readString();
  
  if (newCorrectCode.length() == 5)
  {
    newCorrectCode.trim();
    correctCode = newCorrectCode;
    Serial.println("New code is " + correctCode);
  }
  
  for(i=0; i<=3; i++)
  {
    digitalWrite(row[0],HIGH);
    digitalWrite(row[1],HIGH);
    digitalWrite(row[2],HIGH);
    digitalWrite(row[3],HIGH);
    digitalWrite(row[i],LOW);
    
    for(j=0; j<=3; j++)
    {
      col_scan=digitalRead(col[j]);
      if(col_scan==LOW)
      {
        keypress(i,j);
        delay(300);
      }
    }
  }
  
  if (code.length() == 4)
  {
    if (code == correctCode)
    {
      Serial.println("Code is correct");
      digitalWrite(greenLed, HIGH);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, LOW);
    }
    else
    {
      Serial.println("Code is incorrect");
      digitalWrite(greenLed, LOW);
      digitalWrite(yellowLed, LOW);
      digitalWrite(redLed, HIGH);
    }
    
    delay(5000);
    code = "";
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(redLed, LOW);
  }
}
  
void keypress(int i, int j)
{
  if(i==0&&j==0)
  {
    code += "1";
  }
  if(i==1&&j==0)
  {
    code += "2";
  }
  if(i==2&&j==0)
  {
    code += "3";
  }
  if(i==3&&j==0)
  {
    code += "A";
  }
  if(i==0&&j==1)
  {
    code += "4";
  }
  if(i==1&&j==1)
  {
    code += "5";
  }
  if(i==2&&j==1)
  {
    code += "6";
  }
  if(i==3&&j==1)
  {
    code += "B";
  }
  if(i==0&&j==2)
  {
    code += "7";
  }
  if(i==1&&j==2)
  {
    code += "8";
  }
  if(i==2&&j==2)
  {
    code += "9";
  }
  if(i==3&&j==2)
  {
    code += "C";
  }
  if(i==0&&j==3)
  {
    code += "*";
  }
  if(i==1&&j==3)
  {
    code += "0";
  }
  if(i==2&&j==3)
  {
    code += "#";
  }
  if(i==3&&j==3)
  {
    code += "D";
  }
  
  Serial.println(code);
}