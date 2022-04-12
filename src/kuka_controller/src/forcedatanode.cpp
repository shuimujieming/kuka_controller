/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>

#include <sstream>

#include <kuka_controller/forcedatanode.h>


/*****************************************************************************
** Implementation
*****************************************************************************/

ForcedataNode::ForcedataNode(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
    {}

ForcedataNode::~ForcedataNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();
}

bool ForcedataNode::init() {
    ros::init(init_argc,init_argv,"kuka_control");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    force_publisher = n.advertise<kuka_controller::ForceData>("kuka_forcedata_topic", 1000);
    start();
    return true;
}

bool ForcedataNode::init(const std::string &master_url, const std::string &host_url) {
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
    force_publisher = n.advertise<std_msgs::String>("kuka_forcedata_topic", 1000);
    start();
    return true;
}

//接收力数据函数
void ForcedataNode::receiveForceData(float x,float y,float z,float Mx,float My,float Mz)
{
    forcedata.x = x;
    forcedata.y = y;
    forcedata.z = z;
    forcedata.Mx = Mx;
    forcedata.My = My;
    forcedata.Mz = Mz;
}

void ForcedataNode::getForcePtr(double* x, double*y, double*z, double*mx, double*my, double*mz)
{
    Fx = x;
    Fy = y;
    Fz = z;
    Mx = mx;
    My = my;
    Mz = mz;
}
void ForcedataNode::run() {
    ros::Rate loop_rate(1000);

    int count = 0;

    while ( ros::ok() ) {

        forcedata.x = *Fx;
        forcedata.y = *Fy;
        forcedata.z = *Fz;
        forcedata.Mx = *Mx;
        forcedata.My = *My;
        forcedata.Mz = *Mz;

        force_publisher.publish(forcedata);

        ros::spinOnce();
        loop_rate.sleep();

        count ++;
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


