#ifndef EMS_DATABASE_H
#define EMS_DATABASE_H

#include <QObject>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlDriver>
#include <QtSql/QSqlQuery>
#include <QDebug>
#include <QString>


class ems_database : QObject
{
    Q_OBJECT
public:
    ems_database();
    void open_db(QString host_name, QString db_name, QString user_name, QString password);
    void insert_temperatures_into_db(QString id, int temperature);
    void insert_energy_consumption_int_db(int energy_consumption);
    void insert_air_quality(int air_quality);
    void insert_water_consumption(int water_consumption);


private:

    QSqlDatabase ems_db;
    void check_connection_status();




};

#endif // EMS_DATABASE_H
