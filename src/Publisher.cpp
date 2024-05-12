#include "publisher/Publisher.hpp"

// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>

// STD
#include <string>

namespace pub_sub_comm {

Publisher::Publisher(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  publisher_ = nodeHandle.advertise<std_msgs::String>(publisherTopic_, queue_size_);
  ROS_INFO("Successfully launched node.");
}

Publisher::~Publisher()
{
}

bool Publisher::readParameters()
{
  if (!nodeHandle_.getParam("topic_name", publisherTopic_)) return false;
  if (!nodeHandle_.getParam("queue_size", queue_size_)) return false;
  if (!nodeHandle_.getParam("dummy_string", publishString)) return false;
  if (!nodeHandle_.getParam("publisher_rate_hz", publisher_rate_hz_)) return false;
  return true;
}

void Publisher::mainloop()
{
  unsigned int count = 0;
  while (ros::ok()) {
    std_msgs::String message;
    message.data = publishString + " [Serial Number: " + std::to_string(count) + "]";
    publisher_.publish(message);
    ROS_INFO_STREAM("Most recent published message:" << std::endl << message.data);
    ros::spinOnce();
    ros::Rate(publisher_rate_hz_).sleep();
    count++;
  }
}

} /* namespace */