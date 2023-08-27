// #define USE_USBCON
// #define USE_USB
// #define _SAM3XA_
#define __STM32F1__ //for stm32 bluepill usb serial comms

#include <ros.h>
#include <ros/time.h>
#include <std_msgs/Int16.h>

#include "Motor.h"

ros::NodeHandle  nh;
#define LOOPTIME 10

#define LPWM PA_1
#define RPWM PA_2

int16_t speedVal = 1500;
void joint_callback( const geometry_msgs::Twist& twist){
  // expecting value to be between 1000 to 2000
  speedVal = wheelX_val;
}

ros::Subscriber<std_msgs::Int16> sub("wheel_X", joint_callback );

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  nh.getHardware()->setBaud(57600);

  Motor wheel_XY(LPWM,RPWM);
}

void loop() {
  nh.spinOnce();
  wheel_XY.rotate(speedVal);
}

