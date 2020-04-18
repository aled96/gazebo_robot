#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sensor_msgs/LaserScan.h>


//When a message is received, the associated callback is called
void callbackLaserScan(const sensor_msgs::LaserScan::ConstPtr& msg)
{

    std::vector<float> regions;
    // 720/5 = 144
    ROS_INFO("%d \n",msg->ranges.size());
    float min = HUGE_VALF;
    
    for (int i = 0; i < msg->ranges.size(); i++){
        if(i%144 == 0 && i != 0){
            regions.push_back(min);
            min = HUGE_VALF;
        }
        
        if(min > msg->ranges[i])
            min = msg->ranges[i];
    }
    
    for(int i = 0; i < regions.size(); i++)
        ROS_INFO("%d: %f\n",i,regions[i]);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "reading_laser");
    ros::NodeHandle nh;
    
    ros::Subscriber subscriber = nh.subscribe("/canbot/laser/scan", 2, callbackLaserScan); //Start listening to a topic
    //To specify handler to a method from within the class: ...,10,&ClassName::methodName, this);    

	
    ros::spin(); //Processes callbacks and will not return until the node has been shutdown

    return 0;
}
