# Gazebo ROS Demos

* Author: Alessio De Luca <alessio.deluca.iic96d@gmail.com>
* License: GNU General Public License, version 3 (GPL-3.0)

Example robots and code for interfacing Gazebo with ROS


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
# gazebo_robot
# gazebo_robot
