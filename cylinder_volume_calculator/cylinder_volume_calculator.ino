const int serialBaud = 9600;

const float pi = 3.14;
float diameter = 20;
float height = 10;

void setup()
{
  Serial.begin(serialBaud);
  Serial.println("Calculate the volume of a cylinder");
}

void loop()
{
  Serial.end();
  Serial.begin(serialBaud);
  
  Serial.println("What is the diameter of the cylinder in centimeters?");

  while(Serial.available() == 0)
  { }

  diameter = Serial.parseFloat();
  Serial.println("The diameter is: " + (String)diameter);

  Serial.println("\nWhat is the height of the cylinder centimeters?");

  while(Serial.available() == 1)
  { }

  height = Serial.parseFloat();
  Serial.println("The height is: " + (String)height);

  Serial.println("\n" + CalculateCilinder(diameter, height) + "\n");
}

String CalculateCilinder(float diameter, float height)
{
  float volume = pi * (diameter / 2) * (diameter / 2) * height;

  return("The volume of the cylinder is " + (String)volume + "cm3");
}

boolean isValidNumber(String str)
{
  for(byte i=0; i < str.length(); i++)
  {
    if(isDigit(str.charAt(i)))
    {
      return true;
    }
  }
  
  return false;
}
