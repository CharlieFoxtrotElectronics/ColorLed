/**
 * @file "TestLed.ino"
 * Example sketch for a Quick and dirty 3bit RGB LED class/library for digital pins
 *
 * @authot     Jaime Martínez-Figueroa <jmf@charliefoxtrot.cl>
 * @date       Feb 2016
 * @copyright  2016 Charlie Foxtrot Electronics, LGPL
 */

#include <ColorLed.h>

ColorLed testLed(9, 10, 11); // normal, for common cathode LEDs
// ColorLed testLed(9, 10, 11, NEGATIVE); // negative logic, for common anode LEDs
// ColorLed testLed(9, 10, 11, SINK); // sink or open collector, for common anode LEDs with other voltages


// the setup function runs once when you press reset or power the board
void setup() {
  testLed.setColor(WHITE);
  delay(2000);
}

// the loop function runs over and over again forever
void loop() {
  testLed.setColor(MAGENTA);
  delay(500);

  testLed.setColor(RED);
  delay(500);

  testLed.setColor(YELLOW);
  delay(500);

  testLed.setColor(GREEN);
  delay(500);

  testLed.setColor(CYAN);
  delay(500);
  
  testLed.setColor(BLUE);
  delay(500);
}
