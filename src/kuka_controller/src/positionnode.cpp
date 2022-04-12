/*****************************************************************************
** Includes
*****************************************************************************/

#include <ros/ros.h>
#include <ros/network.h>
#include <string>
#include <std_msgs/String.h>

#include <sstream>

#include <kuka_controller/positionnode.h>


/*****************************************************************************
** Implementation
*****************************************************************************/

PositiondataNode::PositiondataNode(int argc, char** argv ) :
    init_argc(argc),
    init_argv(argv)
    {}

PositiondataNode::~PositiondataNode() {
    if(ros::isStarted()) {
      ros::shutdown(); // explicitly needed since we use ros::start();
      ros::waitForShutdown();
    }
    wait();
}

bool PositiondataNode::init() {
    ros::init(init_argc,init_argv,"kuka_control");
    if ( ! ros::master::check() ) {
        return false;
    }
    ros::start(); // explicitly needed since our nodehandle is going out of scope.
    ros::NodeHandle n;
    // Add your ros communications here.
    position_publisher = n.advertise<kuka_controller::PositionData>("kuka_positiondata_topic", 1000);
    start();
    return true;
}

bool PositiondataNode::init(const std::string &master_url, const std::string &host_url) {
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
    position_publisher = n.advertise<kuka_controller::PositionData>("kuka_positiondata_topic", 1000);
    start();
    return true;
}

void PositiondataNode::getPositionPtr(double* x, double*y, double*z, double*a, double*b, double*c)
{
    X = x;
    Y = y;
    Z = z;
    A = a;
    B = b;
    C = c;
}
void PositiondataNode::run() {
    ros::Rate loop_rate(1000);

    int count = 0;

    while ( ros::ok() ) {

        positiondata.x = *X;
        positiondata.y = *Y;
        positiondata.z = *Z;
        positiondata.a = *A;
        positiondata.b = *B;
        positiondata.c = *C;

        position_publisher.publish(positiondata);

        ros::spinOnce();
        loop_rate.sleep();

        count ++;
    }
    std::cout << "Ros shutdown, proceeding to close the gui." << std::endl;
    emit rosShutdown(); // used to signal the gui for a shutdown (useful to roslaunch)
}


