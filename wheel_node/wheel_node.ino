#define __STM32F1__ //for stm32 bluepill usb serial comms

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Int16.h>

#include "Motor.h"

ros::NodeHandle  nh;
#define LOOPTIME 10

#define LPWM PA1
#define RPWM PA2


int speedVal = 1500;
void wheel_callback( const std_msgs::Int16& value){
  // expecting value to be between 1000 to 2000
  speedVal = value.data;
}

ros::Subscriber<std_msgs::Int16> sub("wheel_L", wheel_callback);

Motor wheel(LPWM,RPWM);

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  nh.getHardware()->setBaud(57600);
}

void loop() {
  nh.spinOnce();
  wheel.rotate(speedVal);
}

