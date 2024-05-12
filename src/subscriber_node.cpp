#include <ros/ros.h>
#include "subscriber/Subscriber.hpp"

int main(int argc, char** argv)
{
  ros::init(argc, argv, "subscriber");
  ros::NodeHandle nodeHandle("~");

  pub_sub_comm::Subscriber subscriber(nodeHandle);

  ros::spin();
  return 0;
}