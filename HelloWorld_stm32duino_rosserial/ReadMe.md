The sketch provided is the generic arduino rosserial hello world code
with an extra ```#define``` statement.

We need the ```#define __STM32F1__``` for the usb-serial communication in stm32 bluepill board. Without this, the code should
compile and upload and rosserial node will connect to the stm32 but show the message:
```unable to sync with device....``` and topic won't be published.

After adding the ```#define __STM32F1__``` line,
compiling this code with default ros_lib will result in an error:


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