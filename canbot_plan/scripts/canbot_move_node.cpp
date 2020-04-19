#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sensor_msgs/LaserScan.h>
#include <canbot_msgs/RegionsLaser.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Vector3.h>
#include <limits>

#define MAX_VEL 0.5
#define STOP_VEL 0.0
#define PI 3.14

ros::Publisher pub;
double inf = std::numeric_limits<float>::infinity();

void callbackRegionsLaser (const canbot_msgs::RegionsLaser::ConstPtr& msg)
{
    int max_index = 0;
    float max= 0;
    
    for (int i = 0; i < msg->regions.size(); i++){
        if(max < msg->regions[i]){
            max = msg->regions[i];
            max_index = i;
        }
    }
    
    geometry_msgs::Twist msg_pub;
    geometry_msgs::Vector3 lin;
    geometry_msgs::Vector3 ang;
    
    ROS_INFO("%d\n",max_index);
    
    if(max != inf && abs(max) < 0.1){
        lin.x = 0;
        ang.z = 0;
    }
    else{
        lin.x = MAX_VEL/2;
        switch(max_index){
            case 0:
                ang.z = -PI/2;
            break;
            case 1:
               ang.z = -PI/5;
            break;
            case 2:
                ang.z = 0;
            break;
            case 3:
               ang.z = PI/5;
            break;
            case 4:
               ang.z = PI/2;
            break;
            default:
                ang.z = 0;
            break;
        }
  
    }
    
    msg_pub.linear = lin;
    msg_pub.angular = ang;
    
    
    pub.publish(msg_pub);
    
}


int main(int argc, char** argv)
{
    ros::init(argc, argv, "canbot_move_node");
    ros::NodeHandle nh;
    
    ros::Subscriber subscriber = nh.subscribe("/canbot/laser/regions", 1, callbackRegionsLaser); //Start listening to a topic
    pub = nh.advertise<geometry_msgs::Twist>("/canbot/cmd_vel", 1); //Create publisher
    
	
    ros::spin(); //Processes callbacks and will not return until the node has been shutdown

    return 0;
}
