# rpi-pico-2040-how-to-use-all-serial-ports
How to get Serial1, Serial2 and SerialPIO functioning, getting the maximum number of serial ports working on the Pico.

### Instructions
Using Earle Philhowers excellent port of the arduino mbed for all rp2040 devices [here](https://learn.adafruit.com/rp2040-arduino-with-the-earlephilhower-core/installing-the-earlephilhower-core), you won't need to get into PIO programming directly, and can instead use the SerialPIO function in the Arduino IDE to gain more serial ports.

### Serial Port Pinouts
|Tx|Rx|Type|Function|
---------------------
|0|1|Serial|Serial1.begin(115200)|



### The problem
I found it problematic to get Serial1 & Serial2 working, using the wrong pins, the pico fails to boot.
So I tested all possible pins for Serial1, and found that Serial1 defaults to 0,1 and can be used on 16,17.
Serial2 I was able to move around a little more freely, however by that stage I stopped testing and opted to use the default board definition of 8,9

### SerialPIO
The manual states 8 serial ports, in reality if you want RX and TX you only get 4, and they work nicely on any set of pins.
You can instead have 8 TX or 8 RX or any combination up to 8 wires.

### Max possible serial ports
In pin order, the sketch uses Serial1 (0,1) SerialPIO (2,3 4,5 6,7) Serial2 (8,9) SerialPIO (10,11) to give a total of 6 serial ports without interfering with the USB port.

### Arduino IDE compile/upload problems
Randomly it fails to upload. To fix: Unplug the pico, hold down the button, plug in the pico, wait a second and let go of the button.
Your compile/upload will now work.
