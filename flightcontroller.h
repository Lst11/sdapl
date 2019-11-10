#ifndef FLIGHTCONTROLLER_H
#define FLIGHTCONTROLLER_H

#include "flight.h"
#include "basecontroller.h"
#include <iostream>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>

class FlightController : public BaseController {
private:
    QString create_flight_table_query = "CREATE TABLE IF NOT EXISTS flights ("
                                        "flight_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        "flight_to_country VARCHAR(255), "
                                        "flight_from_country VARCHAR(255), "
                                        "flight_price real"
                                        ");";

    QString insert_flight_query = " INSERT INTO flights (flight_to_country,flight_from_country,flight_price)"
                                  "VALUES ('%1', '%2', %3 );";

    QString select_flights_query = "SELECT * FROM flights";

public:
    FlightController(const QSqlDatabase &db);

    void save(Flight *flight);

    QSqlQueryModel *findAll();

    void showAll();
};

#endif // FLIGHTCONTROLLER_H
