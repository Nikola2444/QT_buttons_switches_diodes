
make -C led_driver/
insmod led_driver/led_driver.ko

chmod a+x BSL_64bit_executable/BSL
chmod a+x BSL_32bit_executable/BSL

chmod 777 /dev/leds
touch /dev/buttons
chmod 777 /dev/buttons
echo 0b0000 > /dev/buttons
touch /dev/switches
chmod 777 /dev/switches
echo 0b0000 > /dev/switches
