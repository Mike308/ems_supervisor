#include "modbus_communicator.h"

modbus_communicator::modbus_communicator()
{

}

int modbus_communicator::connect_to_modbus_network(char *com_port, int baud_rate, char parity, int data_length, int stop_bit){

     mb_port = modbus_new_rtu(com_port,baud_rate,parity,data_length,stop_bit);

     if(mb_port == NULL){

        return 0;

     }
     if(modbus_connect(mb_port)==-1){

        return -1;

     }else{

         return 1;


     }



}













