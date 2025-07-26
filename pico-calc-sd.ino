#include "PicoCalcSD.hpp"

void setup()
{
  delay(5000);
  PicoCalcSD sd;
  if(sd.write("test.txt", "These NUTS"))
  {
    Serial.println("wrote to sd successfully");
    delay(1000);
    Serial.println("reading same file");
    String data = sd.read("test.txt");
    if(data.length() > 0)
    {
      Serial.println(data);
    }
    else
    {
      Serial.println("Failed to read the same file...");
    }
  }
}

void loop()
{
    // nothing happens after setup
}
