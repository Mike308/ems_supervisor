#ifndef EMS_SUPERVISOR_MAIN_CLASS_H
#define EMS_SUPERVISOR_MAIN_CLASS_H
#define DEBUG

#include <QObject>
#include <QTimer>


#include "qextserialport.h"
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
    QextSerialPort *port;
    ems_database ems_db;
    //uint16_t slave_1[1024];
    //uint16_t slave_2[1024];

    void process_temperature_data(QString temperature_data);
    void process_energy_consumption_data(QString energy_measurement);
    void open_port(QString port_name);
    void serial_port_write(QString data);
    void get_and_process_data_from_slaves(QString s);





public slots:
    void agents_pool_update();
    void onReadyRead();


};

#endif // EMS_SUPERVISOR_MAIN_CLASS_H
