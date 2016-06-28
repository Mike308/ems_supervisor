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

void ems_database::insert_temperatures_into_db(QString id, int temperature){

    QSqlQuery insert_temperatures;

    insert_temperatures.prepare("insert into ds18b20_list (id,temperature) values(:id,:temp)");

    insert_temperatures.bindValue(":id",id);
    insert_temperatures.bindValue(":temp",temperature);

    bool test =  insert_temperatures.exec();
    if(test==true){

        qDebug () <<"OK";
    }else{

        qDebug () <<"FAIL";

    }


}

void ems_database::insert_energy_consumption_int_db(int energy_consumption){

    QSqlQuery insert_energy_consumption;
    int cost = 5 * energy_consumption;
    insert_energy_consumption.prepare("insert into energy_measurements (energy_consum,cost) values(:energy_m,:cost)");

    insert_energy_consumption.bindValue(":energy_m",energy_consumption);
    insert_energy_consumption.bindValue(":cost",cost);

    bool test = insert_energy_consumption.exec();

    if(test==true){

        qDebug () << "OK";

    }else{

        qDebug () << "FAIL";

    }


}

void ems_database::insert_air_quality(int air_quality){

    QSqlQuery insert_air_quality;

    insert_air_quality.prepare("insert into air_quality (concentration) values(:concentration)");

    insert_air_quality.bindValue(":concentration",air_quality);

    bool test = insert_air_quality.exec();

    if(test==true){

        qDebug () << "OK";

    }else{

        qDebug () << "FAIL";

    }

}

void ems_database::insert_water_consumption(int water_consumption){

    QSqlQuery insert_water_consumption;

    insert_water_consumption.prepare("insert into water_measurement (water_consumption) values(:water)");

    insert_water_consumption.bindValue(":water",water_consumption);

    bool test = insert_water_consumption.exec();

    if(test==true){

        qDebug () << "OK";

    }else{

        qDebug () << "FAIL";

    }
}








