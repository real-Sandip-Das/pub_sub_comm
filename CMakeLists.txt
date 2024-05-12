cmake_minimum_required(VERSION 3.0.2)
project(pub_sub_comm)

#Use C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

## Find catkin macros and libraries
find_package(catkin REQUIRED COMPONENTS
  roscpp
)

###################################
## catkin specific configuration ##
###################################
catkin_package(
  INCLUDE_DIRS
    include
  CATKIN_DEPENDS
    roscpp
)

###########
## Build ##
###########

## Specify additional locations of header files
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

## Declare cpp executables
add_executable(publisher
  src/publisher_node.cpp
  src/publisher.cpp
)
add_executable(subscriber
  src/subscriber_node.cpp
  src/subscriber.cpp
)
target_compile_features(publisher INTERFACE cxx_std_11)
target_compile_features(subscribe INTERFACE cxx_std_11)

## Add dependencies to exported targets, like ROS msgs or srvs
add_dependencies(publisher
  ${catkin_EXPORTED_TARGETS}
)
add_dependencies(subscriber
  ${catkin_EXPORTED_TARGETS}
)

## Specify libraries to link executable targets against
target_link_libraries(publisher
  ${catkin_LIBRARIES}
)
target_link_libraries(subscriber
  ${catkin_LIBRARIES}
)

#############
## Install ##
#############

# Mark executables and/or libraries for installation
install(
  TARGETS publisher subscriber #${PROJECT_NAME}_core
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# Mark cpp header files for installation
install(
  DIRECTORY
    include/publisher/
    include/subscriber/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.hpp"
)

# Mark other files for installation
# install(
#   DIRECTORY doc
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_pub_sub_comm.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
