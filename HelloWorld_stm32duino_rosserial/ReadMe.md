The sketch provided is the generic arduino rosserial hello world code
with an extra ```#define``` statement and setting baud rate of the node handler object.

We need the ```#define __STM32F1__``` for the usb-serial communication in stm32 bluepill board. Besides, as stm32 bluepill implements variable baudrate but rosserial doesn't, we need to set the baudrate in the setup() portion of the program by:
```cpp
nh.getHardware()->setBaud(57600);
```
> Here, nh is an object of the NodeHandler class.

Without this, the code should
compile and upload and rosserial node will connect to the stm32 but show the message:
```unable to sync with device....``` and topic won't be published.

After adding these,
compiling the code with default ros_lib will result in an error:


```cpp
In file included from /home/user/.arduino15/libraries/ros_lib/ros.h:43,
                 from /home/user/<PROGRAMDIRECTORY>/HelloWorld_stm32duino_rosserial/HelloWorld_stm32duino_rosserial.ino:7:
/home/user/.arduino15/libraries/ros_lib/ArduinoHardware.h: In constructor 'ArduinoHardware::ArduinoHardware()':
/home/user/.arduino15/libraries/ros_lib/ArduinoHardware.h:75:18: error: cannot convert 'HardwareSerial*' to 'USBSerial*' in assignment
   75 |       iostream = &Serial1;
      |                  ^~~~~~~~
      |                  |
      |                  HardwareSerial*
```

To solve the error, open the ```ros_lib/ArduinoHardware.h``` file, the same file arduino ide showed error at.
After line 59, add this line:
```
#define Serial1 Serial
```
Save the files and compile your stm32 program code in arduino ide again. The problem should be fixed.