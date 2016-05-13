#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "modbus_communicator.h"
#include "ems_supervisor_main_class.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
//    char status_buffer[128];
//    int status;
//    uint16_t data[1024];
//    modbus_communicator mb;
//    main_timer ems_timer(mb);
//    ems_timer.start(1000);
    ems_supervisor_main_class ems;
    ems.start_agents_pooling(1000);




//    status =  mb.check_and_connect_to_modbus_network("COM9",9600,'E',8,1);
//    qDebug() << "Status: " << status;
//    status = mb.check_and_get_data_from_device(9,4,1000,data);









    return a.exec();

}


