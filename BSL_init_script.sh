
make -C led_driver/
if [[ ! -f /dev/leds ]]
then
    echo file exists    
else
    insmod led_driver/led_driver.ko
fi

chmod a+x BSL_64bit_executable/BSL
chmod a+x BSL_32bit_executable/BSL

chmod 777 /dev/leds
echo 0x00000000 > /dev/leds
touch /dev/buttons
chmod 777 /dev/buttons
echo 0x0000 > /dev/buttons
touch /dev/switches
chmod 777 /dev/switches
echo 0x0000 > /dev/switches
