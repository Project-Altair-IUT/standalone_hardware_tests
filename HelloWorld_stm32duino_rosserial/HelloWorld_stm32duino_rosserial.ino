/*
 * rosserial Publisher Example
 * Prints "hello world!"
 */
 
#define __STM32F1__
#include <ros.h>
#include <std_msgs/String.h>

ros::NodeHandle nh;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);

char hello[13] = "hello world!";

void setup() {
  pinMode(PC13, OUTPUT);

  nh.initNode();
  nh.advertise(chatter);
  nh.getHardware()->setBaud(57600);
}

void loop() {
  digitalWrite(PC13, HIGH);
  delay(100);
  digitalWrite(PC13, LOW);
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();
  delay(1000);
}
