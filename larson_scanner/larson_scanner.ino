int leds[] = {0, 1, 2, 3, 4, 5};
int ledsLength = 5;	//sizeof is very slow for some reason so array length is hardcoded

void setup()
{
  for (int i = 0; i < ledsLength; i++)
  {
    pinMode(leds[i], OUTPUT);
  }
}

void loop()
{
  for (int i = 0; i < ledsLength; i++)
  {
    digitalWrite(leds[i], HIGH);
    
    delay(100);
  }

  for (int i = 0; i < ledsLength; i++)
  {
    digitalWrite(leds[i], LOW);

    delay(100);
  }

  for (int i = ledsLength; i >= 0; i--)
  {
    digitalWrite(leds[i], HIGH);

    delay(100);
  }

  for (int i = ledsLength; i >= 0; i--)
  {
    digitalWrite(leds[i], LOW);

    delay(100);
  }
}