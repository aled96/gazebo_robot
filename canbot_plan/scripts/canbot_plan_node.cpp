#include <ros/ros.h>
#include "std_msgs/String.h"
#include <sensor_msgs/LaserScan.h>
#include <canbot_msgs/RegionsLaser.h>

ros::Publisher pub;

//When a message is received, the associated callback is called
void callbackLaserScan(const sensor_msgs::LaserScan::ConstPtr& msg)
{

    std::vector<float> regions;
    std::vector<float>::iterator it;
    
    
    // 720/5 = 144
    float min = HUGE_VALF;
    
    for (int i = 0; i < msg->ranges.size(); i++){
        if((i+1)%144 == 0 && i != 0){
            it = regions.begin();
            regions.insert(it, min);
            min = HUGE_VALF;
        }
        
        if(min > msg->ranges[i])
            min = msg->ranges[i];
    }
    
    canbot_msgs::RegionsLaser msg_pub;
    msg_pub.regions = regions;
    
    pub.publish(msg_pub);
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "reading_laser");
    ros::NodeHandle nh;
    
    ros::Subscriber subscriber = nh.subscribe("/canbot/laser/scan", 2, callbackLaserScan); //Start listening to a topic
    pub = nh.advertise<canbot_msgs::RegionsLaser>("/canbot/laser/regions", 1); //Create publisher
    //To specify handler to a method from within the class: ...,10,&ClassName::methodName, this);    

	
    ros::spin(); //Processes callbacks and will not return until the node has been shutdown

    return 0;
}
