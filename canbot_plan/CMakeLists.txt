cmake_minimum_required(VERSION 2.8.3)
project(canbot_plan)

## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  canbot_msgs
)

#roslaunch_add_file_check(launch)
 

catkin_package(
  CATKIN_DEPENDS
  roscpp
  std_msgs
  geometry_msgs
  canbot_msgs
)

#install(
#  DIRECTORY scripts/
#  DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
#  USE_SOURCE_PERMISSIONS
#)

include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(canbot_dummy_plan_node scripts/canbot_dummy_plan_node.cpp)
target_link_libraries(canbot_dummy_plan_node
   ${catkin_LIBRARIES}
)

add_executable(canbot_dummy_move_node scripts/canbot_dummy_move_node.cpp)
target_link_libraries(canbot_dummy_move_node
   ${catkin_LIBRARIES}
)

