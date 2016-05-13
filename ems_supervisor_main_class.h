#ifndef EMS_SUPERVISOR_MAIN_CLASS_H
#define EMS_SUPERVISOR_MAIN_CLASS_H
#define DEBUG

#include <QObject>
#include <QTimer>

#include "modbus_communicator.h"
#ifdef DEBUG

    #include <QDebug>

#endif



class ems_supervisor_main_class : QObject
{
    Q_OBJECT
public:
    ems_supervisor_main_class();

    void start_agents_pooling(int interval);
    void stop_agents_pooling();

private:
    QTimer *timer;
    modbus_communicator mb;
    uint16_t slave_1[1024];
    uint16_t slave_2[1024];



public slots:
    void agents_pool_update();


};

#endif // EMS_SUPERVISOR_MAIN_CLASS_H
