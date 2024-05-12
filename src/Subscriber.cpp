#include "subscriber/Subscriber.hpp"

// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>

// STD
#include <string>

namespace pub_sub_comm {

Subscriber::Subscriber(ros::NodeHandle& nodeHandle)
    : nodeHandle_(nodeHandle)
{
  if (!readParameters()) {
    ROS_ERROR("Could not read parameters.");
    ros::requestShutdown();
  }
  subscriber_ = nodeHandle_.subscribe(subscriberTopic_, subscriberQueueSize_,
                                      &Subscriber::topicCallback, this);
  ROS_INFO("Successfully launched node.");
}

Subscriber::~Subscriber()
{
}

bool Subscriber::readParameters()
{
  if (!nodeHandle_.getParam("topic_name", subscriberTopic_)) return false;
  if (!nodeHandle_.getParam("queue_size", subscriberQueueSize_)) return false;
  return true;
}

void Subscriber::topicCallback(const std_msgs::String& message)
{
  ROS_INFO_STREAM("I am Subscriber Node, I heard: " << message.data);
}

} /* namespace */