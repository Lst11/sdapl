#ifndef TOURCONTROLLER_H
#define TOURCONTROLLER_H

#include "tour.h"
#include "basecontroller.h"
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>

class TourController: public BaseController{
private:
    QString create_tours_table_query = "CREATE TABLE IF NOT EXISTS tours ("
                                        "tour_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                                        "user_name VARCHAR(255), "
                                        "user_surname VARCHAR(255), "
                                        "user_phone VARCHAR(255), "
                                        "tour_hostel_id INTEGER, "
                                        "tour_flight_id INTEGER, "
                                        "tour_days INTEGER, "
                                        "tour_person_counter INTEGER, "
                                        "FOREIGN KEY(tour_hostel_id) REFERENCES hostels(hostel_id),"
                                        "FOREIGN KEY(tour_flight_id) REFERENCES flights(flight_id)"
                                        ");";

    QString insert_tour_query = " INSERT INTO tours (user_name,user_surname,user_phone,tour_hostel_id,tour_flight_id,tour_days,tour_person_counter)"
                                  "VALUES ('%1', '%2', '%3', %4, %5, %6, %7 );";

    QString select_tours_query = "SELECT * FROM tours "
                                 "INNER JOIN hostels ON hostels.hostel_id = tours.tour_hostel_id "
                                 "INNER JOIN flights ON flights.flight_id = tours.tour_flight_id";

public:
    TourController(const QSqlDatabase &db);

    void save(Tour *tour);

    QSqlQueryModel *findAll();

    void showAll();
};

#endif // TOURCONTROLLER_H
