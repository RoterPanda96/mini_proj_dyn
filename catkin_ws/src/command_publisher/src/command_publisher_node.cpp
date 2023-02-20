#include "command_publisher/command_publisher.h"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "command_publisher_node");
  ros::NodeHandle nh("~");
  CommandPublisher cyclic_command_pub(nh);
  ros::spin();
  return 0;
}