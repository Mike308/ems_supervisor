#include "ems_supervisor_main_class.h"

ems_supervisor_main_class::ems_supervisor_main_class()
{

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(agents_pool_update()));
    mb.check_and_connect_to_modbus_network("COM9",9600,'E',8,1);
    ems_db.open_db("localhost","ems","root","");






}

void ems_supervisor_main_class::start_agents_pooling(int interval){

    timer->start(interval);

}

void ems_supervisor_main_class::stop_agents_pooling(){

    timer->stop();

}


void ems_supervisor_main_class::process_energy_consumption_data(uint16_t *energy_consumption_array){

    int energy_consumption = energy_consumption_array[0];

    ems_db.insert_energy_consumption_int_db(energy_consumption);
    qDebug () << "R1[" << "0" << "]: "<< energy_consumption_array[0];

}

void ems_supervisor_main_class::process_temperature_data(uint16_t *temperature_array){

    for(int register_adress = 0; register_adress<8; register_adress++){

        int sensor_id = temperature_array[register_adress];
        int temperature = temperature_array[register_adress+8];
        ems_db.insert_temperatures_into_db(QString::number(sensor_id),temperature);

        qDebug () << register_adress << "ID: "<< sensor_id << "|" << "Temperatura: " << temperature;



    }


}






void ems_supervisor_main_class::agents_pool_update(){

    int status2 =  mb.check_and_get_data_from_device(9,4,1000,slave_2);
    int status =  mb.check_and_get_data_from_device(10,16,1000,slave_1);
    qDebug () << "Slave: 10" <<  status;
    //qDebug () << "Slave: 9" << status2;

    if(status!=-1){
        process_temperature_data(slave_1);
        process_energy_consumption_data(slave_2);
    }





}
