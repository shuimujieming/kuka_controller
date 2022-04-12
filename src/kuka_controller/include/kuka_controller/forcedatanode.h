#ifndef FORCEDATANODE_H
#define FORCEDATANODE_H

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>

#include <kuka_controller/ForceData.h>

/*****************************************************************************
** Class
*****************************************************************************/

class ForcedataNode : public QThread {
    Q_OBJECT
public:
	ForcedataNode(int argc, char** argv );
	virtual ~ForcedataNode();
	bool init();
	bool init(const std::string &master_url, const std::string &host_url);
	void run();
    //六维力传感器数据
    double *Fx, *Fy, *Fz, *Mx, *My, *Mz;
    void getForcePtr(double* x, double*y, double*z, double*mx, double*my, double*mz);

signals:
    void rosShutdown();

private:
	int init_argc;
	char** init_argv;
    ros::Publisher force_publisher;
    kuka_controller::ForceData forcedata;

public slots:
    void receiveForceData(float x,float y,float z,float Mx,float My,float Mz);
};


#endif /*QNODE_HPP_ */


