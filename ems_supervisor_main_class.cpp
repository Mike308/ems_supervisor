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


void ems_supervisor_main_class::get_and_process_data_from_slaves(QString s){

    qDebug () << "Received data: " << s;

    QStringList items = s.split('^');

    QString id = items[0];
    qDebug () << id;
    if(QString::compare("T",id,Qt::CaseInsensitive)==0){

        process_temperature_data(s);

    }else if(QString::compare("E",id,Qt::CaseInsensitive)==0){

        process_energy_consumption_data(s);

    }



}




void ems_supervisor_main_class::process_energy_consumption_data(QString energy_measurement){

    QStringList energy_measurement_list = energy_measurement.split("^");
    qDebug() << "Energy consumption: " << energy_measurement_list[1];




}

void ems_supervisor_main_class::process_temperature_data(QString temperature_data){

    QStringList temperatures = temperature_data.split('^');

    for(int i=1; i<temperatures.length()-1; i++){

        qDebug() << "T[" << i << "]: " << temperatures[i];


    }


}






void ems_supervisor_main_class::agents_pool_update(){


    static int cnt = 0;

    if(cnt%2==0 || cnt==0){

        serial_port_write("1^1");
        qDebug () << "Debug: " << cnt;

    }else {


        serial_port_write("2^1");
        qDebug () << "Debug: " << cnt;

    }

    cnt++;







}

void ems_supervisor_main_class::onReadyRead(){


    QByteArray bytes;
    if(port->canReadLine()){

        QString str = QString::fromLatin1(port->readLine());

        get_and_process_data_from_slaves(str);


    }

}


