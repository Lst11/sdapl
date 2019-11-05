#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include "flight.h"
#include <iostream>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>

class FlightController {
private:
    QSqlDatabase db;
    QString create_flight_table_query = "CREATE TABLE IF NOT EXISTS flight ("
                                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        "to_country VARCHAR(255), "
                                        "from_country VARCHAR(255), "
                                        "price real"
                                        ");";

    QString insert_flight_query = " INSERT INTO flight (to_country,from_country,price)"
                                  "VALUES ('%1', '%2', %3 );";


public:
    FlightController(const QSqlDatabase &db);

    void createTableFlight();

    void save(Flight *flight);

    QSqlQueryModel *findAll();

    void showAll();
};

#endif // FLIGHTCONTROLLER_H
