int PNP1 = 13;
int PNP2 = 12;

int NPN1 = 7;
int NPN2 = 6;
int NPN3 = 5;
int NPN[3] = {7, 6, 5};
int turn = 0;

// Letter Definitions
int a[2][3] = {
  {1, 0, 0},
  {0, 0, 0}
};

int b[2][3] = {
  {1, 1, 0},
  {0, 0, 0}
};

int c[2][3] = {
  {1, 0, 0},
  {1, 0, 0}
};


void setup() {
  // put your setup code here, to run once:

  pinMode(PNP1, OUTPUT);
  pinMode(PNP2, OUTPUT);

  pinMode(NPN1, OUTPUT);
  pinMode(NPN2, OUTPUT);
  pinMode(NPN3, OUTPUT);


}

void loop() {
  // put your main code here, to run repeatedly:
  turn += 1;
  if ((turn % 2) == 0) {
    digitalWrite(PNP2, HIGH);
    digitalWrite(PNP1, LOW);

    for (int i = 0; i < 2; i++) {
      if (c[0][i] == 1) {
        digitalWrite(NPN[i], HIGH);

      } else {
        digitalWrite(NPN[i], LOW);
      }

    }
    turn = 0;
  }
  else {
    digitalWrite(PNP1, HIGH);
    digitalWrite(PNP2, LOW);
    for (int j = 0; j < 2; j++) {
      if (c[1][j] == 1) {
        digitalWrite(NPN[j], HIGH);
      } else {
        digitalWrite(NPN[j], LOW);
      }
    }
  }

  delay(100);



}
