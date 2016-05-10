#include "modbus_communicator.h"

modbus_communicator::modbus_communicator()
{

}

int modbus_communicator::check_and_connect_to_modbus_network(char *com_port, int baud_rate, char parity, int data_length, int stop_bit){

     mb_port = modbus_new_rtu(com_port,baud_rate,parity,data_length,stop_bit);

     return check_connection_status();



}

int modbus_communicator::check_connection_status(){

    if(mb_port == NULL){

       return NO_CONNECT;

    }
    if(modbus_connect(mb_port)==-1){

       return CONNECTION_ERROR;

    }else{

        return CONNECTION_OK;


    }

}


int modbus_communicator::check_and_select_device(int device_address){

   return modbus_set_slave(mb_port,device_address);

}

int modbus_communicator::check_and_get_data_from_device(int device, int quanity, int addr, uint16_t * data){

    int status = check_and_select_device(device);

    if(status!=0){

        return -1;

    }else {

        return modbus_read_registers(mb_port,addr,quanity,data);


    }



}


















