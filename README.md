# QT_buttons_switches_diodes

This repository contains a simple QT project that emulates diodes, buttons and swithches. To start the application, the files need to be compiled with a make command:

     		make

After the compilation, run the lbt_init_script to generate 3 files in /dev directory (buttons, switches, and leds). Through these files interaction with the leds, switches and buttons is possible. 

When these two steps are finished, just run the generated executable:

./Buttons_switches_diodes

## LEDS
To turn on the leds just write a correct binary string into /dev/leds file. For example,
if you want to turn on the right most diode, you should write:

echo 0x00000001 > /dev/leds

If you want to turn it of, you should write

echo 0x00000000 > /dev/leds

Every bit represents one diode, and if you want to turn them on, or off, you need
to write logic 1 or logic 0 to a correct position.

## BUTTONS

To check if button is pressed just read from /dev/buttons file. If you run a simple read command like "cat" you should get the next output:

cat /dev/buttons

Output: 0x0000

This means that the buttons aren't pressed. If there was a logical 1 on a certain
position, that would mean that one button was pressed.

## Switches

The state of switches is checked in the same manner as the state of buttons.