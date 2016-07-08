#include "ems_supervisor_main_class.h"

ems_supervisor_main_class::ems_supervisor_main_class()
{

    timer = new QTimer(this);
    open_port("COM9");
    connect(timer,SIGNAL(timeout()),this,SLOT(agents_pool_update()));
 //   ems_db.open_db("localhost","ems","root","");






}


void ems_supervisor_main_class::open_port(QString port_name){

    this->port = new QextSerialPort(port_name, QextSerialPort::EventDriven);
    port->setBaudRate(BAUD9600);
    port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    port->open(QIODevice::ReadWrite);

    connect(port, SIGNAL(readyRead()), this, SLOT(onReadyRead()));

}

void ems_supervisor_main_class::serial_port_write(QString data){

    data.append( "\r");
    QByteArray bytes_to_send = data.toLocal8Bit();
    port->write(bytes_to_send);


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


    static int cnt = 0;

    if(cnt%2==0 || cnt==0){

        serial_port_write("1^1");


    }







}

void ems_supervisor_main_class::onReadyRead(){


    QByteArray bytes;
    if(port->canReadLine()){

        QString str = QString::fromLatin1(port->readLine());

        qDebug () << "Received data: " << str;

    }

}


