#pragma once

//ROS
#include <ros/ros.h>
#include <std_msgs/String.h>

namespace pub_sub_comm {

class Publisher
{
  public:
  /*!
   * @brief Constructor.
   *
   * @param nodeHandle the ROS node handle.
   */
  Publisher(ros::NodeHandle& nodeHandle);

  /*!
   * @brief Destructor.
   */
  virtual ~Publisher();

  /*!
   * @brief The main loop of the node(sending dummy messages at a certain interval)
   */
  void mainloop();

 private:
  /*!
   * Reads and verifies the ROS parameters.
   * @return true if successful.
   */
  bool readParameters();

  //! ROS node handle.
  ros::NodeHandle& nodeHandle_;

  //! ROS topic publisher object for sending dummy messages
  ros::Publisher publisher_;

  //! ROS topic name to publish dummy messages to
  std::string publisherTopic_;

  //! String to be published to the ROS topic named publisherTopic_
  std::string publishString;

  //! Rate of sending dummy messages to topic named publisherTopic_
  int publisher_rate_hz_;

  //! Maximum number of outgoing messages to be queued for delivery to subscribers
  int queue_size_;
};

} /* namespace */