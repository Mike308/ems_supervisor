#ifndef MODBUS_COMMUNICATOR_H
#define MODBUS_COMMUNICATOR_H
#include "modbus.h"
#include <QDebug>


class modbus_communicator{

public:
    modbus_communicator();

    int connect_to_modbus_network(char *com_port, int baud_rate, char parity, int data_length, int stop_bits);
//    int select_device(int device_address);
//    int get_data_from_device(int device, int * data);

private:

    modbus_t* mb_port;




};

#endif // MODBUS_COMMUNICATOR_H
