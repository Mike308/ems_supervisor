#ifndef MODBUS_COMMUNICATOR_H
#define MODBUS_COMMUNICATOR_H

#define NO_CONNECT 0
#define CONNECTION_ERROR -1
#define CONNECTION_OK 1

#include "modbus.h"
#include <QDebug>


class modbus_communicator{

public:
    modbus_communicator();

    int check_and_connect_to_modbus_network(char *com_port, int baud_rate, char parity, int data_length, int stop_bits);
    int check_and_select_device(int device_address);
    int check_and_get_data_from_device(int device, int quanity, int addr, uint16_t * data);

private:
    int check_connection_status();
    modbus_t* mb_port;




};

#endif // MODBUS_COMMUNICATOR_H
