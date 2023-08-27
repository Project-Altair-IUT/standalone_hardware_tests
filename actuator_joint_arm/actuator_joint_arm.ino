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

#define LPWM PB_1
#define RPWM PB_2

#define feedback PA_1

#define upperThreshold 900
#define lowerThreshold 100

int16_t speedVal = 1500;
void joint_callback( const geometry_msgs::Twist& twist){
  // expecting value to be between 1000 to 2000
  speedVal = jointX_val;
}

ros::Subscriber<std_msgs::Int16> sub("jointX_val", joint_callback );

void setup() {
  nh.initNode();
  nh.subscribe(sub);

  nh.getHardware()->setBaud(57600);

  Motor jointX(LPWM,RPWM);

  pinMode(feedback, INPUT);
}

void loop() {
  nh.spinOnce();
  feedback_state = analogRead(feedback);
  if (feedback_state > upperThreshold || feedback_state < lowerThreshold)
    speedVal = 1500;
  jointX.rotate(speedVal);
}

