int led = 13;
int pushButtom = 8;
int val = 0;
void setup()
{
    pinMode(led, OUTPUT);
    pinMode(pushButtom, INPUT);
}

void loop()
{
    val = digitalRead(pushButtom); // read input value
    if (val == HIGH) 
    {                              
        digitalWrite(led, HIGH); // turn LED OFF
    }
    else
    {
        digitalWrite(led, LOW); // turn LED ON
    }
   
}