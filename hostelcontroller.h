#ifndef HOSTELCONTROLLER_H
#define HOSTELCONTROLLER_H

#include "Hostel.h"
#include <iostream>
#include <QtSql/QSqlQuery>

class HostelController
{
private:
    QString create_hostel_table_query = "CREATE TABLE [IF NOT EXISTS] hostels ("
                                        "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        "name VARCHAR(255), "
                                        "cost_per_night integer, "
                                        "country VARCHAR(255), "
                                        "city VARCHAR(255)"
                                        ");";
    QString insert_hostel_query = " INSERT INTO hostels (name,cost_per_night,country,city)"
                                  "VALUES ('%1', %2, '%3', '%4' );";
public:
    HostelController();

    void createTableHostel();
    void save(Hostel *hostel);
    void findAll();
    void showAll();

};

#endif // HOSTELCONTROLLER_H
