#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include "modbus.h"
#include "modbus-private.h"
#include "modbus_communicator.h"

using namespace std;
modbus_t* my_modbus;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    char status_buffer[128];

    modbus_communicator mb;

    mb.connect_to_modbus_network("COM10",9600,'E',8,1);





    return a.exec();

}
