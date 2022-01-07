# Arduino-w2811Led-with-Keypad
Use custom palettes with a W2811 LED strip- use a keypad to change palettes. Mostly for my own reference, but it works 100% out of the box, just connect an Uno to a 2811 strip (don't forget to double ground!!!) and add a keypad. 

## Current palettes 
#### Feel free to modify and/or add your own- if you make your own palettes, please fork or make a pull request so I can use them too
*Keypad value (00) : Palette name*
* 00 : Off
* 10 : Ocean (default when you first start the program / restart the Arduino)
* 20 : Forest
* 30 : Clouds
* 40 : Lava
*These first four come with FastLED already. The rest were created by me (and my wife)*
* 50 : Rainforest
* 60 : Tokyo Nights *(this one is meant to recreate the experience of driving through a city at night)*
* 70 : Nosferatu
* 80 : Sandy Beach
* 90 : Omnislash
* 15 : Girl Gang
* 25 : Fairy Fountain
* 35 : Starlight
* 45 : Lemon Orchard
* 55 : Stormy Seas *(this is my personal favorite- watch for the flashes of lightning on the dark ocean waves)*
* 65 : Tropics
* 75 : Hyrule
* 85 : Cinema *(you know those yellow light strips along movie theater aisles? this is that)*
* 95 : Lost Woods
* A0 : Sunset *(this one has a beautiful sequential gradient, highly recommend)*
* B0 : Galaxy
* C0 : Christmas
* D0 : Rainforest Night
* E0 : Mount Hylia

As you can see, this leaves a TON of room for more palettes. The Uno will run out of memory before you run out of 2-digit codes. 

## Hardware defaults
* Data pin for W2811 : 5
* Num LEDS (this is actually num PIXELS on most strips) : 100
* Color order : BRG
* Keypad indicator LED pin : 3

