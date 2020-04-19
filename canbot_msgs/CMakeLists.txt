cmake_minimum_required(VERSION 2.8.3)
project(canbot_msgs)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin
  REQUIRED
  COMPONENTS
  geometry_msgs
  nav_msgs
  message_generation
  genmsg
  actionlib_msgs
)

add_message_files(
   FILES
   RegionsLaser.msg
)

#add_action_files(
#   DIRECTORY
#   action
#   FILES
#   playback.action
#)

generate_messages(
   DEPENDENCIES
   std_msgs
   geometry_msgs
   nav_msgs
   actionlib_msgs
 )

catkin_package(
  CATKIN_DEPENDS
  nav_msgs
  geometry_msgs
  message_runtime
)


