chmod a+x BSL_64bit_executable/BSL
chmod a+x BSL_32bit_executable/BSL
touch /dev/leds
chmod 777 /dev/leds
echo 0x00000000 > /dev/leds
touch /dev/buttons
chmod 777 /dev/buttons
echo 0x0000 > /dev/buttons
touch /dev/switches
chmod 777 /dev/switches
echo 0x0000 > /dev/switches
