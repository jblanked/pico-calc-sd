#include "PicoCalcSD.hpp"

void setup()
{
  Serial.begin(115200);
  delay(5000);
  
  PicoCalcSD sd;
  if (sd.write("test.txt", "Hello, PicoCalc SD!"))
  {
    Serial.println("wrote to sd successfully");
    delay(1000);
    Serial.println("reading same file");
    
    String data = sd.read("test.txt");
    if (data.length() > 0)
    {
      Serial.println(data);
      delay(1000);
      Serial.println("Printing directory contents:");
      
      // List all files and directories in root
      listDirectoryContents(sd, "/");
    }
    else
    {
      Serial.println("Failed to read the same file...");
    }
  }
}

void listDirectoryContents(PicoCalcSD& sd, const char* directoryPath)
{
  Serial.print("Contents of directory: ");
  Serial.println(directoryPath);
  Serial.println("========================================");
  
  int index = 0;
  while (true)
  {
    File entry = sd.getFileOrDirectoryAtIndex(directoryPath, index);
    
    if (!entry)
    {
      // No more files/directories
      break;
    }
    
    Serial.print(index);
    Serial.print(": ");
    Serial.print(entry.name());
    
    if (entry.isDirectory())
    {
      Serial.println("/");
    }
    else
    {
      Serial.print(" (");
      Serial.print(entry.size());
      Serial.println(" bytes)");
    }
    
    entry.close();
    index++;
  }
  
  Serial.print("Total entries found: ");
  Serial.println(index);
  Serial.println("========================================");
}

void loop()
{
  // nothing happens after setup
}