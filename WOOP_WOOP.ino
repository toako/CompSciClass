int red, blue, spkr, redLevel, blueLevel, incRed, incBlue, incSpkr, spkrVal;
bool runSpkr = true;

void setup() {
  Serial.begin(9600);
  red = 6;
  blue = 5;
  spkr = 4;
  redLevel = 5;
  blueLevel = 255;
  incRed = 5;
  incBlue = -5;
  spkrVal = 500;
}

void loop() {

  //LIGHT AREA
  
  if (redLevel <= 0) 
    incRed = 5;
  else if (redLevel >= 255)
    incRed = -5;
  if (blueLevel <= 0) 
    incBlue = 5;
  else if (blueLevel >= 255)
    incBlue = -5;
  redLevel += incRed;
  blueLevel += incBlue;
  analogWrite (red, redLevel);
  analogWrite (blue, blueLevel);

  //SPEAKER AREA

  if (spkrVal <= 500) 
    incSpkr = 5;
  else if (spkrVal >= 1000)
    incSpkr = -5;
  spkrVal += incSpkr;
  Serial.println(spkrVal);
  tone (spkr, spkrVal, 50);
  
  delay(3);
}
