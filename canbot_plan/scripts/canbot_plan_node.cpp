#include <ros/ros.h>
#include "std_msgs/String.h"


int main(int argc, char** argv)
{
    ros::init(argc, argv, "canbot_plane_node");
    ros::NodeHandle nh;
    
    
    ros::spin(); //Processes callbacks and will not return until the node has been shutdown

    return 0;
}
