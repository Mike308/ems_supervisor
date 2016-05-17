#include <QCoreApplication>
#include <QDebug>
#include <iostream>

#include "modbus_communicator.h"
#include "ems_supervisor_main_class.h"

using namespace std;


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    ems_supervisor_main_class ems;
    ems.start_agents_pooling(5000);













    return a.exec();

}


