/**
 * @file "ColorLed.h"
 * Quick and dirty 3bit RGB LED class/library for digital pins
 *
 * @authot     Jaime Martínez-Figueroa <jmf@charliefoxtrot.cl>
 * @date       Feb 2016
 * @copyright  2016 Charlie Foxtrot Electronics, LGPL
 */

#ifndef ColorLed_h
#define ColorLed_h

#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

/**
 * The modes availables for the driver 
 */
enum ColorLedMode_e {
  POSITIVE, ///< Positive mode for common cathode 
  NEGATIVE, ///< Negative mode for common anode
  SINK      ///< Sink mode for common anode hooked-up to a different voltage
};

/**
 * Basic colors
 */
enum ColorLedColor_e {
  BLACK,
  RED,
  GREEN,
  YELLOW,
  BLUE,
  MAGENTA,
  CYAN,
  WHITE
};

/**
 * Quick and dirty 3bit RGB LED class
 */
class ColorLed {
  public:
    /**
     * Constructor method
     * 
     * @param r    Red pin
     * @param g    Green pin
     * @param b    Blue pin
     * @param mode Mode of the LED: POSITIVE for common cathode, NEGATIVE and SINK for common anode
     */
    ColorLed(uint8_t r, uint8_t g, uint8_t b, ColorLedMode_e mode=POSITIVE);

    /**
     * Destructor method (does nothing)
     */
    ~ColorLed();

    /**
     * Sets the color to be displayed and updates the output
     * 
     * @param r Red status (true/false) 
     * @param g Geen status (true/false) 
     * @param b Blue status (true/false) 
     */
    void setColor(bool r, bool g, bool b);

    /**
     * Sets the color to be displayed and updates the output
     * 
     * @param color  The color from the enum: BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE
     */
    void setColor(ColorLedColor_e color);

    /**
     * Turns off all the colors of the LED
     */
    void off();

  private:
    ColorLedMode_e _mode;                           ///< the mode of the LED
    uint8_t _pin[3];                                ///< the pin numbers of the LED
    bool _current_color[3] = {false, false, false}; ///< the current color set

    /**
     * Updates the status of the outputs to match _current_color[]
     */
    void _update();

    /**
     * Sets the color to be displayed
     * 
     * @param r Red status (true/false) 
     * @param g Geen status (true/false) 
     * @param b Blue status (true/false) 
     */
    void _set_color(bool r, bool g, bool b);
};

#endif
