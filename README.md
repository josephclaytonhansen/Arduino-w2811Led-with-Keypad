# Arduino-w2811Led-with-Keypad
Use custom palettes with a W2811 LED strip- use a keypad to change palettes. Mostly for my own reference, but it works 100% out of the box, just connect an Uno to a 2811 strip (don't forget to double ground!!!) and add a keypad. 

## Current palettes 
#### Feel free to modify and/or add your own- if you make your own palettes, please fork or make a pull request so I can use them too
*Keypad value (00) : Palette name*
* 00 : Off
* 10 : Ocean *(default when you first start the program / restart the Arduino)*
* 20 : Forest
* 30 : Clouds
* 40 : Lava
**These first four come with FastLED already. The rest were created by me (and my wife)**
* 50 : Rainforest *(Ever been in a forest when the sunlight is patchy because of the trees?)*
* 60 : Tokyo Nights *(this one is meant to recreate the experience of driving through a city at night)*
* 70 : Nosferatu *(if you don't know why it's purple, you're missing out)*
* 80 : Sandy Beach *(has a fun surprise!)*
* 90 : Omnislash *(This was once called Great Aether, which honestly is more accurate, but both should give you a good mental image)*
* 15 : Girl Gang
* 25 : Fairy Fountain
* 35 : Starlight *(This one is SUPER pretty in the dark)*
* 45 : Lemon Orchard
* 55 : Stormy Seas *(this is my personal favorite- watch for the flashes of lightning on the dark ocean waves)*
* 65 : Tropics *(my wife loves this one, I hate it, it's jewel tones. Use at your own risk)*
* 75 : Hyrule *(kind of Lemon Orchard with added blue, very mesmerizing to watch)*
* 85 : Cinema *(you know those yellow light strips along movie theater aisles? this is that)*
* 95 : Lost Woods *(I made this one nice and slow so you can get the magical experience of going into the Lost Woods for the first time on BOTW and dropping to 5 FPS)*
* A0 : Sunset *(this one has a beautiful sequential gradient, highly recommend)*
* B0 : Galaxy
* C0 : Christmas *(Please don't use this, it was a joke I forgot to take out)*
* D0 : Rainforest Night
* 11 : Mount Hylia *(this is sort of like a snowy, foggy, Sandy Beach)*

As you can see, this leaves a TON of room for more palettes. The Uno will run out of memory before you run out of 2-digit codes. Even if you had unlimited memory on your Uno, though, the number of 2-digit codes doesn't even come CLOSE to how many palettes you could make. 140 web colors and 16 colors in a palette means 8938078073721553883684253696000000 total possible palettes.

## Hardware defaults
* Data pin for W2811 : 5
* Num LEDS (this is actually num PIXELS on most strips) : 100
* Color order : BRG
* Keypad indicator LED pin : 3

