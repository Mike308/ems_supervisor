#include "ems_database.h"

ems_database::ems_database()
{
    ems_db = QSqlDatabase::addDatabase("QMYSQL");

}

void ems_database::open_db(QString host_name, QString db_name, QString user_name, QString password){

    ems_db.setHostName(host_name);
    ems_db.setDatabaseName(db_name);
    ems_db.setUserName(user_name);
    ems_db.setPassword(password);

    if(!ems_db.open()){

        qDebug () << "Problem with establishing connection with database";

    }else{

        qDebug () << "IS OK";

    }
}




