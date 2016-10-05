#include "ems_database.h"

ems_database::ems_database()
{
    ems_db = QSqlDatabase::addDatabase("QMYSQL");

}

void ems_database::check_connection_status(){

    if(!ems_db.open()){

        qDebug () << "Problem with establishing connection with database";

    }else{

        qDebug () << "IS OK";

    }
}

void ems_database::open_db(QString host_name, QString db_name, QString user_name, QString password){

    ems_db.setHostName(host_name);
    ems_db.setDatabaseName(db_name);
    ems_db.setUserName(user_name);
    ems_db.setPassword(password);

    check_connection_status();



}



void ems_database::insert_into_current_measurement(QString id, float result){

    QSqlQuery insert_temperatures;

    insert_temperatures.prepare("insert into current_measurment (phase_no,result) values(:phase_no,:result)");

    insert_temperatures.bindValue(":phase_no",id);
    insert_temperatures.bindValue(":result",temperature);

    bool test =  insert_temperatures.exec();
    if(test==true){

        qDebug () <<"OK";
    }else{

        qDebug () <<"FAIL";

    }


}

void ems_database::insert_into_power_measurement(int energy_consumption){

    QSqlQuery insert_energy_consumption;

    insert_energy_consumption.prepare("insert into energy_measurements (energy_consum) values(:energy_m)");

    insert_energy_consumption.bindValue(":energy_m",energy_consumption);

    bool test = insert_energy_consumption.exec();

    if(test==true){

        qDebug () << "OK";

    }else{

        qDebug () << "FAIL";

    }


}






