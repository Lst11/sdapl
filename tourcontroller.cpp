#include "tourcontroller.h"
#include <iostream>
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

TourController::TourController(const QSqlDatabase &db) : db(db) {
    createTableTours();
}

void TourController::createTableTours() {

    db.open();
    if (!db.open()) {
        qDebug() << db.lastError().text();
        qDebug() << "cant open connection";
    }

    QSqlQuery query;
    bool successQuery = query.exec(create_tours_table_query);
    if (!successQuery) {
        qDebug() << db.lastError() << endl;
        qDebug() << "cant create table tours!";
    } else {
        qDebug() << "created the table tours!";
    }
    db.close();
}

void TourController::save(Tour *tour) {
    db.open();

    QString tour_to_insert = insert_tour_query.arg(QString::fromStdString(tour->getUser()->getName()))
            .arg(QString::fromStdString(tour->getUser()->getSurname()))
            .arg(QString::fromStdString(tour->getUser()->getPhone()))
            .arg(tour->getHostelId())
            .arg(tour->getFlightId())
            .arg(tour->getNightCounter())
            .arg(tour->getPersonCounter());

    QSqlQuery query;
    bool successQuery = query.exec(tour_to_insert);
    if (!successQuery) {
        qDebug() << db.lastError() << endl;
        qDebug() << "Can't save the tour to database!";
    } else {
        qDebug() << "The tour was saved to database!";
    }
    db.close();
}

QSqlQueryModel *TourController::findAll() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM tours")) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

void TourController::showAll() {
    db.open();
    QSqlQuery query;

//    if (!query.exec("SELECT * FROM tours")) {
//        qDebug() << "Select query doesn't work.";
//    }

    if (!query.exec("SELECT * FROM tours "
                    "INNER JOIN hostels ON hostels.hostel_id = tours.tour_hostel_id "
                    "INNER JOIN flights ON flights.flight_id = tours.tour_flight_id")) {
        qDebug() << "Select query doesn't work.";
    }

    QSqlRecord rec = query.record();

    while (query.next()) {
        int id = query.value(rec.indexOf("tour_id")).toInt();
        QString userName = query.value(rec.indexOf("user_name")).toString();
        QString userSurname = query.value(rec.indexOf("user_surname")).toString();
        QString userPhone = query.value(rec.indexOf("user_phone")).toString();

        int hostelId = query.value(rec.indexOf("tour_hostel_id")).toInt();
        int flightId = query.value(rec.indexOf("tour_flight_id")).toInt();
        int days = query.value(rec.indexOf("tour_days")).toInt();
        int persons = query.value(rec.indexOf("tour_person_counter")).toInt();

        qDebug() << "id is " << id
                 << ". user name: " << userName
                 << ". user surname: " << userSurname
                 << ". user phone: " << userPhone
                 << ". hostelId is " << hostelId
                 << ". flightId is " << flightId
                 << ". days is: " << days
                 << ". persons" << persons;
    }
    db.close();
}
