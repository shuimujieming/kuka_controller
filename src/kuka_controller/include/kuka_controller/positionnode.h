#ifndef POSITIONNODE_H
#define POSITIONNODE_H

#ifndef Q_MOC_RUN
#include <ros/ros.h>
#endif
#include <string>
#include <QThread>

#include <kuka_controller/PositionData.h>

/*****************************************************************************
** Class
*****************************************************************************/

class PositiondataNode : public QThread {
    Q_OBJECT
public:
        PositiondataNode(int argc, char** argv );
        virtual ~PositiondataNode();
        bool init();
        bool init(const std::string &master_url, const std::string &host_url);
        void run();

        double *X, *Y, *Z, *A, *B, *C;
        void getPositionPtr(double* x, double*y, double*z, double*a, double*b, double*c);



signals:
    void rosShutdown();

private:
        int init_argc;
        char** init_argv;
    ros::Publisher position_publisher;
    kuka_controller::PositionData positiondata;

public slots:

};


#endif // POSITIONNODE_H
