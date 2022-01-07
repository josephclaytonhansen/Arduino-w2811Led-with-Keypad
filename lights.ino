

// Use this example with the Adafruit Keypad products.
// You'll need to know the Product ID for your keypad.
// Here's a summary:
//   * PID3844 4x4 Matrix Keypad
//   * PID3845 3x4 Matrix Keypad
//   * PID1824 3x4 Phone-style Matrix Keypad
//   * PID1332 Membrane 1x4 Keypad
//   * PID419  Membrane 3x4 Matrix Keypad

#include "Adafruit_Keypad.h"
#include <SoftwareSerial.h>
#include <FastLED.h>

#define LED_PIN     5
#define NUM_LEDS    100
#define BRIGHTNESS  100
#define LED_TYPE    WS2811
#define COLOR_ORDER BRG
CRGB leds[NUM_LEDS];

int UPDATES_PER_SECOND = 40;
CRGBPalette16 currentPalette;
TBlendType    currentBlending;

extern CRGBPalette16 Rainforest;
extern CRGBPalette16 Tokyo;
extern const TProgmemPalette16 Rainforest_p PROGMEM;
extern const TProgmemPalette16 Tokyo_p PROGMEM;
extern const TProgmemPalette16 Nosferatu_p PROGMEM;
extern const TProgmemPalette16 SandyBeach_p PROGMEM;
extern const TProgmemPalette16 Omnislash_p PROGMEM;
extern const TProgmemPalette16 GirlGang_p PROGMEM;
extern const TProgmemPalette16 FairyFountain_p PROGMEM;
extern const TProgmemPalette16 Off_p PROGMEM;
extern const TProgmemPalette16 Starlight_p PROGMEM;
extern const TProgmemPalette16 LemonOrchard_p PROGMEM;
extern const TProgmemPalette16 StormySea_p PROGMEM;
extern const TProgmemPalette16 Tropics_p PROGMEM;
extern const TProgmemPalette16 Hyrule_p PROGMEM;
extern const TProgmemPalette16 Cinema_p PROGMEM;
extern const TProgmemPalette16 LostWoods_p PROGMEM;
extern const TProgmemPalette16 Sunset_p PROGMEM;
extern const TProgmemPalette16 Galaxy_p PROGMEM;
extern const TProgmemPalette16 Christmas_p PROGMEM;

// define your specific keypad here via PID
#define KEYPAD_PID3844
// define your pins here
// can ignore ones that don't apply
#define R1    13
#define R2    12
#define R3    11
#define R4    10
#define C1    9
#define C2    8
#define C3    7
#define C4    6
// leave this import after the above configuration
#include "keypad_config.h"

//initialize an instance of class NewKeypad
Adafruit_Keypad customKeypad = Adafruit_Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS);

char input[] = "";
String input_string = String(input);
 
void setup() {
  Serial.begin(9600);
  customKeypad.begin();
  pinMode(3, OUTPUT);
  currentPalette = OceanColors_p;
  currentBlending = LINEARBLEND;

  delay( 3000 ); // power-up safety delay
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setBrightness(  BRIGHTNESS );
}

void loop() {
  // put your main code here, to run repeatedly:
  static uint8_t startIndex = 0;
  startIndex = startIndex + 1; /* motion speed */

  FillLEDsFromPaletteColors( startIndex);

  FastLED.show();
  FastLED.delay(1000 / UPDATES_PER_SECOND);
  customKeypad.tick();

  while(customKeypad.available()){
    keypadEvent e = customKeypad.read();
    digitalWrite(3, HIGH);
    
    if(e.bit.EVENT == KEY_JUST_PRESSED) {
      input_string.concat((char)e.bit.KEY);
      if (input_string.length() == 2)
      {
        Serial.println(input_string);
        
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        delay(100);
        digitalWrite(3, HIGH);
        delay(100);
        digitalWrite(3, LOW);
        
        delay(100);

        if (input_string == "10")
        {
          currentPalette = OceanColors_p;
          UPDATES_PER_SECOND = 40;
        }
        if (input_string == "20")
        {
          currentPalette = ForestColors_p;
          UPDATES_PER_SECOND = 40;
        }
        if (input_string == "30")
        {
          currentPalette = CloudColors_p;
          UPDATES_PER_SECOND = 40;
        }
        if (input_string == "40")
        {
          currentPalette = LavaColors_p;
          UPDATES_PER_SECOND = 40;
        }
        if (input_string == "50")
        {
          currentPalette = Rainforest_p;
          UPDATES_PER_SECOND = 40;
        }
        if (input_string == "60")
        {
          currentPalette = Tokyo_p;
          UPDATES_PER_SECOND = 40;
        }
        if (input_string == "70")
        {
          currentPalette = Nosferatu_p;
          UPDATES_PER_SECOND = 52;
        }
        if (input_string == "80")
        {
          currentPalette = SandyBeach_p;
          UPDATES_PER_SECOND = 40;

        }
        if (input_string == "90")
        {
          currentPalette = Omnislash_p;
          UPDATES_PER_SECOND = 60;

        }
        if (input_string == "15")
        {
          currentPalette = GirlGang_p;
          UPDATES_PER_SECOND = 40;

        }
        if (input_string == "25")
        {
          currentPalette = FairyFountain_p;
          UPDATES_PER_SECOND = 40;

        }
        if (input_string == "00")
        {
          currentPalette = Off_p;
          UPDATES_PER_SECOND = 1;

        }
        if (input_string == "35")
        {
          currentPalette = Starlight_p;
          UPDATES_PER_SECOND = 25;

        }
        if (input_string == "45")
        {
          currentPalette = LemonOrchard_p;
          UPDATES_PER_SECOND = 40;


        }
        if (input_string == "55")
        {
          currentPalette = StormySea_p;
          UPDATES_PER_SECOND = 50;


        }
        if (input_string == "65")
        {
          currentPalette = Tropics_p;
          UPDATES_PER_SECOND = 40;


        }
        if (input_string == "75")
        {
          currentPalette = Hyrule_p;
          UPDATES_PER_SECOND = 40;


        }
        if (input_string == "85")
        {
          currentPalette = Cinema_p;
          UPDATES_PER_SECOND = 40;


        }
        if (input_string == "95")
        {
          currentPalette = LostWoods_p;
          UPDATES_PER_SECOND = 35;


        }
        if (input_string == "A0")
        {
          currentPalette = Sunset_p;
          UPDATES_PER_SECOND = 20;

        }
        if (input_string == "B0")
        {
          currentPalette = Galaxy_p;
          UPDATES_PER_SECOND = 20;

        }
        if (input_string == "C0")
        {
          currentPalette = Christmas_p;
          UPDATES_PER_SECOND = 25;

        }
        input_string = "";
          
      }
      
    }
    else if(e.bit.EVENT == KEY_JUST_RELEASED) {
      digitalWrite(3, LOW);
      }
  }

}

void FillLEDsFromPaletteColors( uint8_t colorIndex)
{
  uint8_t brightness = 255;

  for ( int i = 0; i < NUM_LEDS; i++) {
    leds[i] = ColorFromPalette( currentPalette, colorIndex, brightness, currentBlending);
    colorIndex += 3;
  }
}

const TProgmemPalette16 Rainforest_p PROGMEM =
{
  CRGB::DarkGreen,
  CRGB::DarkGreen,
  CRGB::LimeGreen,
  CRGB::Black,
  CRGB::Olive,
  CRGB::Green,
  CRGB::DarkGreen,
  CRGB::ForestGreen,
  CRGB::Black,
  CRGB::Olive,
  CRGB::DarkGreen,
  CRGB::LimeGreen,
  CRGB::YellowGreen,
  CRGB::Olive,
  CRGB::Green,
  CRGB::LimeGreen,
};

const TProgmemPalette16 Tokyo_p PROGMEM =
{
  CRGB::Black,
  CRGB::Orange,
  CRGB::Black,
  CRGB::LightBlue,
  CRGB::Turquoise,
  CRGB::Teal,
  CRGB::Black,
  CRGB::Black,
  CRGB::Yellow,
  CRGB::Orange,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Blue,
  CRGB::LightBlue,
  CRGB::White,
};

const TProgmemPalette16 Nosferatu_p PROGMEM =
{
  CRGB::DarkMagenta,
  CRGB::Indigo,
  CRGB::Purple,
  CRGB::Violet,
  CRGB::DarkOrchid,
  CRGB::Orchid,
  CRGB::Purple,
  CRGB::Violet,
  CRGB::DarkMagenta,
  CRGB::Indigo,
  CRGB::Orchid,
  CRGB::Purple,
  CRGB::Fuchsia,
  CRGB::DarkMagenta,
  CRGB::Purple,
  CRGB::Violet,
};

const TProgmemPalette16 SandyBeach_p PROGMEM =
{
  CRGB::Aqua,
  CRGB::SkyBlue,
  CRGB::SteelBlue,
  CRGB::Aqua,
  CRGB::Teal,
  CRGB::Aqua,
  CRGB::Aqua,
  CRGB::SteelBlue,
  CRGB::Goldenrod,
  CRGB::SandyBrown,
  CRGB::SandyBrown,
  CRGB::Bisque,
  CRGB::SteelBlue,
  CRGB::Aqua,
  CRGB::Teal,
  CRGB::SkyBlue,
};
const TProgmemPalette16 Omnislash_p PROGMEM =
{
  CRGB::Teal,
  CRGB::White,
  CRGB::Blue,
  CRGB::LightGreen,
  CRGB::Aquamarine,
  CRGB::White,
  CRGB::LightBlue,
  CRGB::LightGreen,
  CRGB::White,
  CRGB::Teal,
  CRGB::Blue,
  CRGB::LightBlue,
  CRGB::White,
  CRGB::White,
  CRGB::LightGreen,
  CRGB::Aquamarine,
};
const TProgmemPalette16 GirlGang_p PROGMEM =
{
  CRGB::Pink,
  CRGB::PaleVioletRed,
  CRGB::Salmon,
  CRGB::IndianRed,
  CRGB::Tomato,
  CRGB::Cornsilk,
  CRGB::Pink,
  CRGB::HotPink,
  CRGB::Crimson,
  CRGB::LightCoral,
  CRGB::PaleVioletRed,
  CRGB::DarkRed,
  CRGB::Pink,
  CRGB::White,
  CRGB::Salmon,
  CRGB::Pink,
};
const TProgmemPalette16 Off_p PROGMEM =
{
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
  CRGB::Black,
};
const TProgmemPalette16 FairyFountain_p PROGMEM =
{
  CRGB::OrangeRed,
  CRGB::Orange,
  CRGB::Yellow,
  CRGB::Crimson,
  CRGB::DeepPink,
  CRGB::Pink,
  CRGB::White,
  CRGB::Pink,
  CRGB::DeepPink,
  CRGB::Crimson,
  CRGB::White,
  CRGB::Yellow,
  CRGB::Orange,
  CRGB::OrangeRed,
  CRGB::Aqua,
  CRGB::Orange,
};
const TProgmemPalette16 Starlight_p PROGMEM =
{
  CRGB::Navy,
  CRGB::MidnightBlue,
  CRGB::Indigo,
  CRGB::DarkMagenta,
  CRGB::Turquoise,
  CRGB::DeepSkyBlue,
  CRGB::White,
  CRGB::DarkMagenta,
  CRGB::Navy,
  CRGB::White,
  CRGB::Magenta,
  CRGB::Orchid,
  CRGB::Indigo,
  CRGB::White,
  CRGB::DarkTurquoise,
  CRGB::MidnightBlue,
};
const TProgmemPalette16 LemonOrchard_p PROGMEM =
{
  CRGB::Yellow,
  CRGB::Yellow,
  CRGB::LightYellow,
  CRGB::YellowGreen,
  CRGB::GreenYellow,
  CRGB::Olive,
  CRGB::Goldenrod,
  CRGB::Gold,
  CRGB::SandyBrown,
  CRGB::Goldenrod,
  CRGB::LightYellow,
  CRGB::Yellow,
  CRGB::DarkGreen,
  CRGB::Olive,
  CRGB::LightYellow,
  CRGB::White,
};
const TProgmemPalette16 StormySea_p PROGMEM =
{
  CRGB::Navy,
  CRGB::MidnightBlue,
  CRGB::Indigo,
  CRGB::DarkMagenta,
  CRGB::DarkTurquoise,
  CRGB::Navy,
  CRGB::Black,
  CRGB::DarkMagenta,
  CRGB::Black,
  CRGB::Black,
  CRGB::White,
  CRGB::Black,
  CRGB::DarkOrchid,
  CRGB::Indigo,
  CRGB::Magenta,
  CRGB::DarkTurquoise,

};
const TProgmemPalette16 Tropics_p PROGMEM =
{
  CRGB::Maroon,
  CRGB::DeepPink,
  CRGB::DarkGreen,
  CRGB::DarkCyan,
  CRGB::DarkBlue,
  CRGB::DarkMagenta,
  CRGB::Yellow,
  CRGB::OrangeRed,
  CRGB::Aqua,
  CRGB::Crimson,
  CRGB::DarkRed,
  CRGB::Lime,
  CRGB::Maroon,
  CRGB::Teal,
  CRGB::Brown,
  CRGB::DarkGreen,

};
const TProgmemPalette16 Cinema_p PROGMEM =
{
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::SandyBrown,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,

};
const TProgmemPalette16 LostWoods_p PROGMEM =
{
  CRGB::SteelBlue,
  CRGB::PaleTurquoise,
  CRGB::LightCyan,
  CRGB::PowderBlue,
  CRGB::DodgerBlue,
  CRGB::DarkCyan,
  CRGB::CornflowerBlue,
  CRGB::SteelBlue,
  CRGB::RoyalBlue,
  CRGB::SlateGray,
  CRGB::LightSeaGreen,
  CRGB::Turquoise,
  CRGB::AliceBlue,
  CRGB::SteelBlue,
  CRGB::DeepSkyBlue,
  CRGB::DarkSlateGray,

};

const TProgmemPalette16 Hyrule_p PROGMEM =
{
  CRGB::DarkGreen,
  CRGB::Goldenrod,
  CRGB::DarkOliveGreen,
  CRGB::DarkGreen,
  CRGB::Green,
  CRGB::ForestGreen,
  CRGB::Gold,
  CRGB::YellowGreen,
  CRGB::SpringGreen,
  CRGB::Aquamarine,
  CRGB::Gold,
  CRGB::YellowGreen,
  CRGB::LightGreen,
  CRGB::LimeGreen,
  CRGB::DeepSkyBlue,
  CRGB::ForestGreen,
};
const TProgmemPalette16 Sunset_p PROGMEM =
{
  CRGB::Yellow,
  CRGB::Orange,
  CRGB::DarkOrange,
  CRGB::OrangeRed,
  CRGB::MediumVioletRed,
  CRGB::Crimson,
  CRGB::Red,
  CRGB::DarkRed,
  CRGB::Maroon,
  CRGB::Indigo,
  CRGB::Navy,
  CRGB::MidnightBlue,
  CRGB::Black,
  CRGB::MidnightBlue,
  CRGB::MediumBlue,
  CRGB::White,
};
const TProgmemPalette16 Galaxy_p PROGMEM =
{
  CRGB::MidnightBlue,
  CRGB::Indigo,
  CRGB::BlueViolet,
  CRGB::Black,
  CRGB::DarkSlateGray,
  CRGB::Navy,
  CRGB::Black,
  CRGB::DarkSlateBlue,
  CRGB::Indigo,
  CRGB::Indigo,
  CRGB::DarkMagenta,
  CRGB::DarkSlateGray,
  CRGB::Black,
  CRGB::MidnightBlue,
  CRGB::Indigo,
  CRGB::Silver,
};
const TProgmemPalette16 Christmas_p PROGMEM =
{
  CRGB::DarkGreen,
  CRGB::DarkGreen,
  CRGB::Lime,
  CRGB::White,
  CRGB::DarkRed,
  CRGB::DarkRed,
  CRGB::Red,
  CRGB::White,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::Goldenrod,
  CRGB::White,
  CRGB::DarkRed,
  CRGB::DarkRed,
  CRGB::DarkRed,
  CRGB::Silver,
};
