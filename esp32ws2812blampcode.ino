#include <FastLED.h>

#define NUM_LEDS 8
#define DATA_PIN 13
#define BUTTON_PIN 15

CRGB leds[NUM_LEDS];

void setup() {
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Set button pin as input with pull-up resistor
}

void loop() {
  static int mode = 0; // Initialize mode variable to 0

  if (digitalRead(BUTTON_PIN) == LOW) { // Check if button is pressed (NC button is normally closed)
    mode++; // Increment mode variable

    switch (mode) { // Choose mode based on mode variable
      case 1:
        fire();
        break;
      case 2:
        rainbow();
        break;
      case 3:
        twinkle();
        break;
      case 4:
        twinkleRandomColors();
        break;
      case 5:
        fill_solid(leds, NUM_LEDS, CRGB::Red);
        FastLED.show();
        break;
      case 6:
        fill_solid(leds, NUM_LEDS, CRGB::Green);
        FastLED.show();
        break;
      case 7:
        fill_solid(leds, NUM_LEDS, CRGB::Blue);
        FastLED.show();
        break;
      case 8:
        fill_solid(leds, NUM_LEDS, CRGB::Cyan);
        FastLED.show();
        break;
      case 9:
        fill_solid(leds, NUM_LEDS, CRGB::Yellow);
        FastLED.show();
        break;
      case 10:
        fill_solid(leds, NUM_LEDS, CRGB::Magenta);
        FastLED.show();
        break;
      case 11:
        fill_solid(leds, NUM_LEDS, CRGB::White);
        FastLED.show();
        break;
      case 12:
        fill_solid(leds, NUM_LEDS, CRGB::Black); // Turn off all LEDs
        FastLED.show();
        break;
      default:
        mode = 0; // Reset mode variable to 0
        break;
    }

    delay(500); // Delay to debounce button
  }

  if (mode == 1) { // If in fire mode, display the fire effect
    fire();
  } else if (mode == 2) { // If in rainbow mode, display the rainbow effect
    rainbow();
  } else if (mode == 3) { // If in twinkle mode, display the twinkle effect
    twinkle();
  } else if (mode == 4) { // If in twinkle with random colors mode, display the twinkle effect with random colors
    twinkleRandomColors();
  }
}

void fire() {
  static uint8_t heat[NUM_LEDS]; // Declare heat array as a static variable

  // Step 1. Cool down every LED a little
  for (int i = 0; i < NUM_LEDS; i++) {
    heat[i] = qsub8(heat[i], random8(0, ((NUM_LEDS * 10) / NUM_LEDS) + 2));
  }

  // Step 2. Sparking from hot to cold
  if (random8() < 150) {
    int cooldown = random8(10, 60);
    int index = random8(NUM_LEDS);
    heat[index] = qadd8(heat[index], cooldown);
  }

  // Step 3. Map heat to LED colors
  for (int i = 0; i < NUM_LEDS; i++) {
    CRGB color = HeatColor(heat[i]);
    leds[i] = color;
  }

  FastLED.show();
  delay(120); // Delay increased to slow down the fire effect
}

void rainbow() {
  static uint8_t hue = 0; // Declare hue variable as a static variable

  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(hue + (i * 255 / NUM_LEDS), 255, 255);
  }

  FastLED.show();
  delay(10);

  hue++; // Increment hue variable to move rainbow effect
}

void twinkle() {
  fadeToBlackBy(leds, NUM_LEDS, 20); // Fade all LEDs by 20

  for (int i = 0; i < NUM_LEDS; i++) {
    if (random8() < 30) { // 30% chance of twinkle
      leds[i] = CRGB::White;
    }
  }

  FastLED.show();
  delay(120); // Delay increased to slow down the twinkle effect
}

void twinkleRandomColors() {
  fadeToBlackBy(leds, NUM_LEDS, 20); // Fade all LEDs by 20

  for (int i = 0; i < NUM_LEDS; i++) {
    if (random8() < 30) { // 30% chance of twinkle
      leds[i] = CHSV(random8(), 255, 255); // Set random color for the twinkle
    }
  }

  FastLED.show();
  delay(120); // Delay increased to slow down the twinkle effect
}
