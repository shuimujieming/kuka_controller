#ifndef CONTROLNODE_H
#define CONTROLNODE_H

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>

#include "MyTCP.h"
#include <kuka_controller/KukaControl.h>

/*****************************************************************************
** Class
*****************************************************************************/

class ControlNode : public QThread {
    Q_OBJECT
public:
	ControlNode(int argc, char** argv );
	virtual ~ControlNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();


    void getTCPPtr(MyTCP* tcp);


signals:
        void rosShutdown();
private:
	int init_argc;
	char** init_argv;
    ros::ServiceServer control_server;
    bool senddata(kuka_controller::KukaControl::Request  &req,
             kuka_controller::KukaControl::Response &res);
    MyTCP* tcpPtr = NULL;

};

#endif /*QNODE_HPP_ */

