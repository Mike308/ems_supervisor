#include "ems_supervisor_main_class.h"

ems_supervisor_main_class::ems_supervisor_main_class()
{

    timer = new QTimer(this);
    open_port("COM9");
    connect(timer,SIGNAL(timeout()),this,SLOT(agents_pool_update()));
    ems_db.open_db("localhost","ems2","root","");






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
    if(QString::compare("E",id,Qt::CaseInsensitive)==0){

        QString l1_current_str = items[1];
        QString l2_current_str = items[2];
        QString l3_current_str = items[3];



        float l1_current = l1_current_str.toFloat();
        float l2_current = l2_current_str.toFloat();
        float l3_current = l3_current_str.toFloat();



        qDebug() << l1_current << "^" << l2_current;


        ems_db.insert_into_current_measurement(1,l1_current);
        ems_db.insert_into_current_measurement(2,l2_current);
        ems_db.insert_into_current_measurement(3,l3_current);

        float ac_voltage = ems_db.get_voltage();

        float  l1_apparent_power = l1_current*ac_voltage;
        float  l2_apparent_power = l2_current*ac_voltage;
        float  l3_apparent_power = l3_current*ac_voltage;

        ems_db.insert_into_power_measurement(1,l1_apparent_power);
        ems_db.insert_into_power_measurement(2,l2_apparent_power);
        ems_db.insert_into_power_measurement(3,l3_apparent_power);








    }



}













void ems_supervisor_main_class::agents_pool_update(){


  serial_port_write("s");







}

void ems_supervisor_main_class::onReadyRead(){


    QByteArray bytes;
    if(port->canReadLine()){

        QString str = QString::fromLatin1(port->readLine());

        get_and_process_data_from_slaves(str);


    }

}


