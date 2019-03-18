// Example 2 - Receive with an end-marker
// number of chars in command string
const int numChars = 8;
char data[numChars]; // an array to store the received data
int pins[6] =
{
    2, 3, 4, 5, 6, 7
};

// states of each pin ( 1 or 0 ) (set to 2 as error checking)
int state[6] =
{
    0, 0, 0, 0, 0, 0
};

boolean newData = false;
void setup()
{
    Serial.begin(9600);
    Serial.println("Arduino is ready");
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT);
    pinMode(13, OUTPUT);
}

void loop()
{
    receivedata();
    ProcessNewData();
    //testpin();
    setPins();
}

void receivedata() // function to check serial and add incoming serial data to char array data
{
    static byte ndx = 0;
    char endMarker = '/';
    char received;
    while (Serial.available() > 0 && newData == false)
    {
        received = Serial.read();
        if (received != endMarker)
        {
            //add new char to data char array
            data[ndx] = received;
            //Iterate index value
            ndx++;
            if (ndx >= numChars)
            {
                ndx = numChars - 1;
            }
        }
        else
        {
            data[ndx] = '\0'; // terminate the string
            ndx = 0;
            newData = true;
        }
    }
}

void ProcessNewData() // process data char array in to 'state' int array
{
    if (newData == true)
    {
        Serial.print("This just in ... ");
        Serial.println(data);
       // state = {2,2,2,2,2,2};
        for (int i = 0; i < 6; i++) {
            int val;
            // convert char to int (-'0')
            if (isdigit(data[i])) {
                val = data[i] - '0';
            }
            else {
                val = 2;

            }
            // assign state value to data value as an int
            state[i] = val;
            val = 0;
        }
        newData = false;
        Serial.print(state[0]);
        // Serial.print(",");
        Serial.print(state[1]);
        Serial.print(state[2]);
        Serial.print(state[3]);
        Serial.print(state[4]);
        Serial.println(state[5]);
        //setPins();
    }
}

void setPins() // iterate through state and assign pins to HIGH or LOW based on state value
{
    //Serial.println(state[0]);
    //Iterate through state
    for (int i = 0; i < 6; i++)
    {
       int p = i + 2;
        switch (state[i]) {
            case 0 :
              digitalWrite(p, LOW);
              break;
            case 1 :
              digitalWrite(p, HIGH);
              break;
            case 2 :
                Serial.print("Error 2: Unknown Character: ");
                Serial.println(state[i]);
                break;
            default:
              Serial.print("Error: default - char: ");
              Serial.println(state[i]);

        }
        /*if (state[i] == 1)
        {
            int p = i + 2;
            digitalWrite(p, HIGH);
        }
        if (state[i] == 0)
        {
            int p = i + 2;
            digitalWrite(p, LOW);
        if (state[i] == 2) 
        {
            Serial.println("Error: State = 2 - non-digit char sent"); // This means state has not been reassigned since beginning - should be 1 or 0
        }
        else  
        {
            Serial.print("Error: Unknown Character");
            Serial.println(state[i]);
        }
        }
    }*/
    }
}

void testpin() // Function to test individual pins and other debugging
{
    // digitalWrite(3, HIGH);
 
 

}
