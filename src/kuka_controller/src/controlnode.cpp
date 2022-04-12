/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>

#include <sstream>

#include <kuka_controller/controlnode.h>

/*****************************************************************************
** Implementation
*****************************************************************************/

ControlNode::ControlNode(int argc, char** argv ) :
	init_argc(argc),
	init_argv(argv)
	{}

ControlNode::~ControlNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
	wait();
}
void ControlNode::getTCPPtr(MyTCP* tcp)
{
    tcpPtr = tcp;
}
//服务端回调函数
//bool类型才能用于service
bool ControlNode::senddata(kuka_controller::KukaControl::Request  &req,
         kuka_controller::KukaControl::Response &res)
{
  res.ret = tcpPtr->CtrlRobot(req.x,req.y,req.z,req.a,req.b,req.c);
  return true;
}

bool ControlNode::init() {
    ros::init(init_argc,init_argv,"kuka_control");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;

	// Add your ros communications here.
    control_server = n.advertiseService("kuka_control_service",&ControlNode::senddata,this);
	start();
	return true;
}

bool ControlNode::init(const std::string &master_url, const std::string &host_url) {
	std::map<std::string,std::string> remappings;
	remappings["__master"] = master_url;
	remappings["__hostname"] = host_url;
    ros::init(remappings,"kuka_control");
	if ( ! ros::master::check() ) {
		return false;
	}
	ros::start(); // explicitly needed since our nodehandle is going out of scope.
	ros::NodeHandle n;
	// Add your ros communications here.
    control_server = n.advertiseService("kuka_control_service",&ControlNode::senddata,this);
    start();
	return true;
}

void ControlNode::run() {

    ROS_INFO("Ready to receive to control robot.");
	while ( ros::ok() ) {
        ros::spin();
	}

	std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


