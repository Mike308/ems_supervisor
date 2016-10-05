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



void ems_database::insert_into_current_measurement(int id, float result){

    QSqlQuery insert_current_measurement;

    insert_current_measurement.prepare("insert into current_measurement (phase_no,result) values(:phase_no,:result)");

    insert_current_measurement.bindValue(":phase_no",id);
    insert_current_measurement.bindValue(":result",result);

    bool test =  insert_current_measurement.exec();

    if(test==true){

        qDebug () <<"OK";
    }else{

        qDebug () <<"FAIL";
        qDebug () << insert_current_measurement.lastError();

    }


}

void ems_database::insert_into_power_measurement(int id, float result){

    QSqlQuery insert_power_measurement;

    insert_power_measurement.prepare("insert into power_measurement (phase_no,result) values(:phase_no,:result)");

    insert_power_measurement.bindValue(":phase_no",id);
    insert_power_measurement.bindValue(":result",result);

    bool test =  insert_power_measurement.exec();
    if(test==true){

        qDebug () <<"OK";
    }else{

        qDebug () <<"FAIL";

    }


}






