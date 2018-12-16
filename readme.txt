This is the code I used for my Collaborative Instrument Prototype.

"button_ultra" is the Arduino sketch that starts serial communication from the buttons and ultrasonic sensor.
This information is then translated through a Max for Live patch called "system" so it can control parameters
in Ableton.



Code References

"button_ultra" 
The ultrasonic sensor part was based on "Arduino - Ultrasonic Sensor" by tutorialspoint
https://www.tutorialspoint.com/arduino/arduino_ultrasonic_sensor.htm

The button part of the code was based on "MAX msp 7: Sending data from arduino into Max" by
Programming for People.
https://www.youtube.com/watch?v=6bT3G4Mep7E



"system" was based on an Ableton preset effect called Expression Control and a patch called Dimmer by 
David A. Mellis, modified by myself and Harry Morley.

Expression Control effect by Ableton
https://www.ableton.com/en/manual/max-for-live-devices/ 

Dimmer by David A. Mellis
https://www.arduino.cc/en/Tutorial/Dimmer 

