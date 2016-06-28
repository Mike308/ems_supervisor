#include "ems_supervisor_main_class.h"
#include <fstream>


ems_supervisor_main_class::ems_supervisor_main_class()
{

    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(agents_pool_update()));
    int status =  mb.check_and_connect_to_modbus_network("/dev/ttyUSB0",9600,'E',8,1);
    qDebug()<<"Status"<< status;
    ems_db.open_db("localhost","EMS","root","code6699");






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

void ems_supervisor_main_class::process_air_quality(int air_quality){

    ems_db.insert_air_quality(air_quality);

}

void ems_supervisor_main_class::process_water_consumption(int water){

    ems_db.insert_water_consumption(water);
}






void ems_supervisor_main_class::agents_pool_update(){




      if(cnt%2==0 || cnt == 0){

          int status = mb.check_and_get_data_from_device(10,16,1000,slave_1);
          qDebug() << "Slave 10: " << status ;
          process_temperature_data(slave_1);
          process_air_quality((rand()%50)+1000);
          process_water_consumption((rand()%50)+100);


      }else{

          int status2 = mb.check_and_get_data_from_device(9,4,1000,slave_2);
          qDebug() << "Slave 9: " << status2 ;
          process_energy_consumption_data(slave_2);
      }




    cnt++;





}
