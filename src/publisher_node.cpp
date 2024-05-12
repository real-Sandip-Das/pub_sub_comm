#include <ros/ros.h>
#include "publisher/Publisher.hpp"

int main(int argc, char* argv[]) {
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nodeHandle("~");
  pub_sub_comm::Publisher publisher(nodeHandle);
  publisher.mainloop();

  return 0;
}