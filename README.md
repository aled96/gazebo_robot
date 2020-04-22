# Gazebo ROS Demos

* Author: Alessio De Luca <alessio.deluca.iic96d@gmail.com>
* License: GNU General Public License, version 3 (GPL-3.0)

Example robots and code for interfacing Gazebo with ROS

## Installation
Install ROS:
    sudo apt-get install ros-kinetic-desktop-full (CHECK)
Install others:
    sudo apt-get install ros-kinetic-map-server ros-kinetic-move-base ros-kinetic-nav-core ros-kinetic-base-local-planner ros-kinetic-clear-costmap-recovery ros-kinetic-costmap-2d ros-kinetic-navfn ros-kinetic-rotate-recovery ros-kinetic-amcl


## Quick Start

Rviz:

     rviz rviz ~/test_canbot_ws/src/canbot_gazebo/worlds/rviz_config.rviz

Gazebo:

    roslaunch canbot_gazebo canbot.launch

ROS Control:

    Launched by gazebo launcher

Example of Moving Joints:

    rostopic pub -1 /canbot/leftWheel_effort_controller/command std_msgs/Float64 "data: 1.5"

## Develop and Contribute

We welcome any contributions to this repo and encourage you to fork the project then send pull requests back to this parent repo. Thanks for your help!
# How to Run
    roslaunch canbot_gazebo canbot.launch
    ( rviz rviz ~/test_canbot_ws/src/canbot_gazebo/worlds/rviz_config.rviz) --> Inside canbot.launch
    roslaunch canbot_gazebo canbot_slam.launch --> Launch gmapping and load map
    
    (rosrun map_server map_saver -f /home/alessio/test_map  --> To save the map built)
    
    roslaunch canbot_2dnav canbot_move_plan.launch --> Launch planning part
    
    rosrun simple_navigation_goals simple_navigation_goals --> Call the action to move based on the plan
# TODO
- Path Planning
- Improve model (Arm?)
- Improve control
