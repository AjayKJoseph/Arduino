
// Example 3 - Receive with start- and end-markers

const byte numChars = 5;
char receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
    pinMode(9,OUTPUT);
}

void loop() {
    recvWithStartEndMarkers();
    showNewData();
//    if (receivedChars[2]!= receivedChars[2])
//    {
      analogWrite(3, receivedChars[0]); analogWrite(11, receivedChars[1]); analogWrite(9, receivedChars[2]); analogWrite(10, receivedChars[3]);
//    }
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    char startMarker = '<';
    char endMarker = '>';
    int rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("This just in ... ");
        Serial.print(receivedChars[0]); Serial.print("\t"); Serial.print(receivedChars[1]); Serial.print("\t"); Serial.print(receivedChars[2]); Serial.print("\t"); Serial.println(receivedChars[3]);   
        newData = false;
    }
}




/*=======================================================================================================================================

// Example 3 - Receive with start- and end-markers

const byte numChars = 4;
int receivedChars[numChars];

boolean newData = false;

void setup() {
    Serial.begin(115200);
    Serial.println("<Arduino is ready>");
}

void loop() {
    recvWithStartEndMarkers();
    showNewData();
}

void recvWithStartEndMarkers() {
    static boolean recvInProgress = false;
    static byte ndx = 0;
    byte startMarker = 0x3C;//'<'
    byte endMarker = 0x3E; // '>'
    int rc;
 
    while (Serial.available() > 0 && newData == false) {
        rc = Serial.read();

        if (recvInProgress == true) {
            if (rc != endMarker) {
                receivedChars[ndx] = rc;
                ndx++;
                if (ndx >= numChars) {
                    ndx = numChars - 1;
                }
            }
            else {
                receivedChars[ndx] = '\0'; // terminate the string
                recvInProgress = false;
                ndx = 0;
                newData = true;
            }
        }

        else if (rc == startMarker) {
            recvInProgress = true;
        }
    }
}

void showNewData() {
    if (newData == true) {
        Serial.print("Received Ints "); Serial.print(receivedChars[0]); //Serial.print("/t"); Serial.print(receivedChars[1]); Serial.print("\t"); Serial.print(receivedChars[2]); Serial.print("\t"); Serial.println(receivedChars[3]);
        newData = false;
    }
}

*/
