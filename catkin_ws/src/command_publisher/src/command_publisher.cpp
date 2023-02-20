#include "command_publisher/command_publisher.h"

CommandPublisher::CommandPublisher(ros::NodeHandle& nh) : nh_(nh) 
{
  readParameters();
  server_.setCallback(boost::bind(&CommandPublisher::dynamicReconfigureCallback, this, _1, _2));
  cmd_vel_pub_ = nh_.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
  timer_ = nh_.createTimer(ros::Duration(0.1), &CommandPublisher::timerCallback, this);
}

CommandPublisher::~CommandPublisher()
 {
    nh_.deleteParam("linear_vel");
    nh_.deleteParam("angular_vel");
  }

void CommandPublisher::dynamicReconfigureCallback(command_publisher::velocityConfig &config, uint32_t level) 
{
  linear_vel_ = config.linear_vel;
  angular_vel_ = config.angular_vel;
}

void CommandPublisher::timerCallback(const ros::TimerEvent& event) 
{
  geometry_msgs::Twist msg;
  msg.linear.x = linear_vel_;
  msg.angular.z = angular_vel_;
  cmd_vel_pub_.publish(msg);
}

void CommandPublisher::readParameters() 
{
  nh_.param("linear_vel", linear_vel_, 0.0);
  nh_.param("angular_vel", angular_vel_, 0.0);
}
