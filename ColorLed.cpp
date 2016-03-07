/**
 * @file "ColorLed.cpp"
 * Quick and dirty 3bit RGB LED class/library for digital pins
 *
 * @authot     Jaime Martínez-Figueroa <jmf@charliefoxtrot.cl>
 * @date       Feb 2016
 * @copyright  2016 Charlie Foxtrot Electronics, LGPL
 */

#include "ColorLed.h"

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/**
 * Constructor method
 * 
 * @param r    Red pin
 * @param g    Green pin
 * @param b    Blue pin
 * @param mode Mode of the LED: POSITIVE for common cathode, NEGATIVE and SINK for common anode
 */
ColorLed::ColorLed(uint8_t r, uint8_t g, uint8_t b, ColorLedMode_e mode) {
  _pin[0] = r;
  _pin[1] = g;
  _pin[2] = b;

  _mode = mode;

  _update();
}

/**
 * Destructor method (does nothing)
 */
ColorLed::~ColorLed() {
  // does nothing
}

/**
 * Sets the color to be displayed
 * 
 * @param r Red status (true/false) 
 * @param g Geen status (true/false) 
 * @param b Blue status (true/false) 
 */
void ColorLed::setColor(bool r, bool g, bool b) {
  _set_color(r, g, b);

  _update();
}

/**
 * Sets the color to be displayed
 * 
 * @param color  The color from the enum: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
 */
void ColorLed::setColor(ColorLedColor_e color) {
  switch(color) {
    case RED:
      _set_color(true, false, false);
      break;

    case GREEN:
      _set_color(false, true, false);
      break;

    case YELLOW:
      _set_color(true, true, false);
      break;

    case BLUE:
      _set_color(false, false, true);
      break;

    case MAGENTA:
      _set_color(true, false, true);
      break;

    case CYAN:
      _set_color(false, true, true);
      break;

    case WHITE:
      _set_color(true, true, true);
      break;

    case BLACK:
    default:
      _set_color(false, false, false);
      break;
  }

  _update();
}

/**
 * Turns off all the colors of the LED
 */
void ColorLed::off() {
  _set_color(false, false, false);

  _update();
}

/**
 * Updates the status of the outputs to match _current_color[]
 */
void ColorLed::_update() {
  uint8_t i;

  for(i = 0; i < 3; i++) {
    switch(_mode) {
      case SINK:
        if(_current_color[i]) {
          pinMode(_pin[i], OUTPUT);
          digitalWrite(_pin[i], LOW);
        }
        else {
          pinMode(_pin[i], INPUT);
          digitalWrite(_pin[i], LOW);
        }
        break;

      case NEGATIVE:
        pinMode(_pin[i], OUTPUT);
        
        if(_current_color[i])
          digitalWrite(_pin[i], LOW);
        else
          digitalWrite(_pin[i], HIGH);

        break;

      case POSITIVE:
      default:
        pinMode(_pin[i], OUTPUT);

        if(_current_color[i])
          digitalWrite(_pin[i], HIGH);
        else
          digitalWrite(_pin[i], LOW);

        break;

    }
  }
}

/**
 * Sets the color to be displayed
 * 
 * @param r  Red status (true/false) 
 * @param g  Geen status (true/false) 
 * @param b  Blue status (true/false) 
 */
void ColorLed::_set_color(bool r, bool g, bool b) {
  _current_color[0] = r;
  _current_color[1] = g;
  _current_color[2] = b;
}
