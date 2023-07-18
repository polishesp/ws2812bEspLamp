#ws2812bEspLamp #ws2812b #lamp #arduino #esp #esp32

Components Required:
  -ESP32 development board
  -WS2812B LED strip (with the desired number of LEDs)
  -Momentary push-button
  -Resistor (around 10k ohms)
  -USB cable for programming and powering the lamp

Step 1: Circuit Connections:
  -Connect the 5V pin of the WS2812B LED strip to the 5V pin of the ESP32 board.
  -Connect the GND (Ground) pin of the LED strip to the GND pin of the ESP32 board.
  -Connect the DATA IN pin of the LED strip to a digital pin on the ESP32 board (pin 13).
  -Connect one terminal of the push-button to a digital pin on the ESP32 board (pin 15).
  -Connect the other terminal of the push-button to the 3.3V pin of the ESP32 board.
  -Connect one end of the resistor to the same digital pin to which the push-button is connected.
  -Connect the other end of the resistor to the GND pin of the ESP32 board.
  -Make sure to double-check your connections and ensure that the LED strip is properly connected to the power supply (5V) and the ESP32 board.

Step 2: Code Setup:
  -Set up your Arduino development environment and make sure the FastLED library is installed. You can refer to the official Arduino website for instructions on setting up the environment and library installation.
  -Adjust code for your lamp if you are using other number of LEDs (line 3, NUM_LEDS).
  -Upload the code to your ESP32 board.
  
Step 3: Testing:
  -Power up your ESP32 board.
  -Press the button connected to the ESP32 board.
  -The code will cycle through different lighting effects on the WS2812B LED strip. Each press of the button will switch to the next lighting effect.
  -Verify that the WS2812B LEDs display the desired lighting effect as per the selected mode.
  -Ensure that the LED strip and the button are connected correctly, and the data pin and button pin specified in the code match the physical connections you made.

Note: Remember to adjust the pin assignments in the code if you connected the LEDs or button to different pins on the ESP32 board.

That's it! You have successfully connected WS2812B LEDs, a button, and a resistor to an ESP32 board and uploaded the provided code to control the lighting effects. Feel free to modify the code or circuit as per your specific requirements.
