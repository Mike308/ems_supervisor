#ifndef EMS_SUPERVISOR_MAIN_CLASS_H
#define EMS_SUPERVISOR_MAIN_CLASS_H
#define DEBUG

#include <QObject>
#include <QTimer>


#include "modbus_communicator.h"
#include "ems_database.h"

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
    ems_database ems_db;
    uint16_t slave_1[1024];
    uint16_t slave_2[1024];

    void process_temperature_data(uint16_t *temperature_array);
    void process_energy_consumption_data(uint16_t *energy_consumption_array);




public slots:
    void agents_pool_update();


};

#endif // EMS_SUPERVISOR_MAIN_CLASS_H
