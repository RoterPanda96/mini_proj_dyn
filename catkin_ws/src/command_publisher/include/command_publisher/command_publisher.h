#ifndef COMMAND_PUBLISHER_H
#define COMMAND_PUBLISHER_H

#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "dynamic_reconfigure/server.h"
#include "command_publisher/velocityConfig.h"

class CommandPublisher
{
public:
  CommandPublisher(ros::NodeHandle& nh);
  ~CommandPublisher();

private:
  ros::NodeHandle nh_;
  ros::Publisher cmd_vel_pub_;
  ros::Timer timer_;
  dynamic_reconfigure::Server<command_publisher::velocityConfig> server_;
  double linear_vel_, angular_vel_;

  void dynamicReconfigureCallback(command_publisher::velocityConfig &config, uint32_t level);
  void timerCallback(const ros::TimerEvent& event);
  void readParameters();
};

#endif // COMMAND_PUBLISHER_H
