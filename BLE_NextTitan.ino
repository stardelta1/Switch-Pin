/*
 * Sample to 
 * Switching on output pin
 */
char data = 0;                //Variable for storing received data
#define power 13          //Arduino PIN 13 for power display
#define relay 11              //Arduino PIN 11 for relay control

void setup() {
  Serial.begin(9600);             //Sets the data rate in bits per second (baud) for serial data transmission
  pinMode(relay, OUTPUT);         //Sets digital pin 13 as output pin
  pinMode(power, OUTPUT);     //For output power displayed
}
void loop() {

   digitalWrite(power, HIGH);        //Permanently turn ON LED for power display 
   
  if(Serial.available() > 0) { // Send data only when you receive data:
    data = Serial.read();      //Read the incoming data and store it into variable data
    Serial.print(data);        //Print Value inside data in Serial monitor
    Serial.print("\n");        //New line 
    if(data == '1')            //Checks whether value of data is equal to 1 
      digitalWrite(relay, LOW);  //If value is 1 then switch RELAY OFF
    else if(data == '0')       //Checks whether value of data is equal to 0
      digitalWrite(relay, HIGH);   //If value is 0 then Switch  RELAY ON
  }                             
}



