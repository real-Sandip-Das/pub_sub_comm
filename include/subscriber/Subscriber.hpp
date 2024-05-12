#pragma once

// ROS
#include <ros/ros.h>
#include <std_msgs/String.h>

namespace pub_sub_comm {

class Subscriber
{
 public:
  /*!
   * Constructor.
   * @param nodeHandle the ROS node handle.
   */
  Subscriber(ros::NodeHandle& nodeHandle);

  /*!
   * Destructor.
   */
  virtual ~Subscriber();

 private:
  /*!
   * Reads and verifies the ROS parameters.
   * @return true if successful.
   */
  bool readParameters();

  /*!
   * ROS topic callback method.
   * @param message the received message.
   */
  void topicCallback(const std_msgs::String& message);

  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic subscriber for laser scan data.
  ros::Subscriber subscriber_;

  //! ROS topic name to subscribe to for laser scan data.
  std::string subscriberTopic_;

  //! Queue size of the subscriber object subscriber_
  int subscriberQueueSize_;
};

} /* namespace */