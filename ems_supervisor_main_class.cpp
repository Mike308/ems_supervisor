#include "ems_supervisor_main_class.h"

ems_supervisor_main_class::ems_supervisor_main_class()
{
  timer = new QTimer(this);
  connect(timer,SIGNAL(timeout()),this,SLOT(agents_pool_update()));
  //mb.check_and_connect_to_modbus_network("COM9",9600,'E',8,1);
  ems_db.open_db("localhost","ems","root","");
  ems_db.insert_temperatures_into_db("23F",69);



}

void ems_supervisor_main_class::start_agents_pooling(int interval){

    timer->start(interval);

}

void ems_supervisor_main_class::stop_agents_pooling(){

    timer->stop();

}

void ems_supervisor_main_class::agents_pool_update(){

//  mb.check_and_get_data_from_device(9,4,1000,slave_1);
//  mb.check_and_get_data_from_device(10,4,1000,slave_2);

//  for(int i=0; i<4; i++){

//      qDebug () << "R1" << "[ " << i << "]" << ": " << slave_1[i];


//  }

//  for(int i=0; i<4; i++){

//      qDebug () << "R2" << "[ " << i << "]" << ": " << slave_2[i];


//  }


}
