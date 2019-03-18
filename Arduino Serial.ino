
int cmd = 0;
char data[7];
char lastdata[7] = "123456";
bool newdata = false;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  Serial.println("Ready:");
  //Set pin modes to OUTPUT
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(13, OUTPUT);
}


void loop() {
  recieve_data();   

// Pin Actuation
  delay(1);        // delay in between reads for stability
}


void printdata() {
  strcpy(lastdata, data);
  Serial.print("Data: ");
  Serial.println(lastdata);
}

void processdata() {
  if (lastdata[2] == '1') {
    digitalWrite(13, HIGH);
  }
}



void recieve_data(){
  int i = 0;
  while (Serial.available() > 0 ) {
      char recieved = Serial.read();

      if (recieved != '/') {
        for (int i = 0; i < 7; i++) {
          data[i] = recieved;
        }
        }
      else {
        data[i] = '\0';
        i = 0;

        printdata();
        processdata();

      }
  }
}
