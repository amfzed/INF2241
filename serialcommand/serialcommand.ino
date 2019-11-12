String readString; 

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200); 
}

void loop() {
  // put your main code here, to run repeatedly:

      if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      if (c=='\n') { //if newline then process
        Serial.println(readString); //print whole string 
        String firstWord = getValue(readString,' ',0);
        String secondWord = getValue(readString,' ',1);
        String thirdWord = getValue(readString,' ',2);
        readString="";
        Serial.println(firstWord); 
        Serial.println(secondWord);
        Serial.println(thirdWord);
        if ((firstWord == "Matt") && (secondWord == "was") && (thirdWord =="here")) {
          Serial.println("happy you were here, Matt!");  
        }
      }else{
      if (isAscii(c)) readString += c; //makes the string readString
    }  
    }
}

String getValue(String data, char separator, int index)
{
  int found = 0;
  int strIndex[] = {0, -1};
  int maxIndex = data.length()-1;

  for(int i=0; i<=maxIndex && found<=index; i++){
    if(data.charAt(i)==separator || i==maxIndex){
        found++;
        strIndex[0] = strIndex[1]+1;
        strIndex[1] = (i == maxIndex) ? i+1 : i;
    }
  }

  return found>index ? data.substring(strIndex[0], strIndex[1]) : "";
}
