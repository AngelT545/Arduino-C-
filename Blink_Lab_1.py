const int my_led_pin = 4;
const int my_sensor_pin =5;
int my_sensor_state = -1;
// 
void setup() {
  // put your setup code here, to run once:
pinMode(my_led_pin, OUTPUT);
pinMode(my_sensor_pin, INPUT_PULLUP);
}


void loop() {
  // put your main code here, to run repeatedly:
my_sensor_state=digitalRead(my_sensor_pin);
digitalWrite(my_led_pin, my_sensor_state);
}
