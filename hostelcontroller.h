#ifndef HOSTELCONTROLLER_H
#define HOSTELCONTROLLER_H

#include "Hostel.h"
#include <basecontroller.h>
#include <iostream>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>

class HostelController : public BaseController {
private:
    QString create_hostel_table_query = "CREATE TABLE IF NOT EXISTS hostels ("
                                        "hostel_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        "hostel_name VARCHAR(255), "
                                        "hostel_cost_per_night integer, "
                                        "hostel_country VARCHAR(255), "
                                        "hostel_city VARCHAR(255)"
                                        ");";
    QString insert_hostel_query = " INSERT INTO hostels (hostel_name,hostel_cost_per_night,hostel_country,hostel_city)"
                                  "VALUES ('%1', %2, '%3', '%4' );";

    QString select_hostels_query = "SELECT * FROM hostels";

    QString find_by_id_hostel_query = "SELECT * FROM hostels WHERE hostel_id = %1";

public:
    HostelController(const QSqlDatabase &db);

    void save(Hostel *hostel);

    QSqlQueryModel *findAll();

    QSqlQueryModel *findAllByCountry(string countryName);

    QSqlQueryModel *findAllSortedByPrice();

    QSqlQueryModel *findAllSortedByCountry();

    Hostel *findById(int hostelId);

    void showAll();

private:

    Hostel *convertToHostel(QSqlRecord entity);
};

#endif // HOSTELCONTROLLER_H
