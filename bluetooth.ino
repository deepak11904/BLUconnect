#include "BluetoothSerial.h" //Header File for Serial Bluetooth, will be added by default into Arduino
BluetoothSerial ESP_BT; //Object for Bluetooth
int incoming;
int LED = 23;
void setup() {
Serial.begin(9600); //Start Serial monitor in 9600
ESP_BT.begin("BLUE10"); //Name of your Bluetooth Signal as u want show while search availble BT
Serial.println("Bluetooth Device is Ready to Pair");
pinMode (LED, OUTPUT);//Specify that LED pin is output
}

void loop() {
if (ESP_BT.available()) //Check if we receive anything from Bluetooth
  {
    incoming = ESP_BT.read(); //Read what we recevive 
    Serial.print("Received:"); Serial.println(incoming);
    if (incoming == 49)  // ASCII value of 1 (49-48=1)
        {
        digitalWrite(LED, HIGH);
        ESP_BT.println("LED turned ON");
        Serial.println("LED turned ON");
        }
    if (incoming == 48) // ASCII value of 0 (48-48=0)
        {
        digitalWrite(LED, LOW);
        ESP_BT.println("LED turned OFF");
        Serial.println("LED turned OFF");
        }     
  }
  delay(20);
}
