#include "flightcontroller.h"
#include "flight.h"
#include <iostream>
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

FlightController::FlightController(const QSqlDatabase &db) : db(db) {
    createTableFlight();
}

void FlightController::createTableFlight() {

    db.open();
    if (!db.open()) {
        qDebug() << db.lastError().text();
        qDebug() << "cant open connection";
    }

    QSqlQuery query;
    bool successQuery = query.exec(create_flight_table_query);
    if (!successQuery) {
        qDebug() << db.lastError() << endl;
        qDebug() << "cant create table flight!";
    } else {
        qDebug() << "created the table flight!";
    }
    db.close();
}

void FlightController::save(Flight *flight) {
    db.open();

    QString flight_to_insert = insert_flight_query.arg(QString::fromStdString(flight->getToCountry()))
            .arg(QString::fromStdString(flight->getFromCountry()))
            .arg(flight->getPrice());

    QSqlQuery query;
    bool successQuery = query.exec(flight_to_insert);
    if (!successQuery) {
        qDebug() << db.lastError() << endl;
        qDebug() << "Can't save the flight to database!";
    } else {
        qDebug() << "The flight was saved to database!";
    }
    db.close();
}

QSqlQueryModel *FlightController::findAll() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM flight")) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

void FlightController::showAll() {
    db.open();
    QSqlQuery query;

    if (!query.exec("SELECT * FROM flight")) {
        qDebug() << "Select query doesn't work.";
    }
    QSqlRecord rec = query.record();

    while (query.next()) {
        int id = query.value(rec.indexOf("id")).toInt();
        QString toCountry = query.value(rec.indexOf("to_country")).toString();
        QString fromCountry = query.value(rec.indexOf("from_country")).toString();
        double price = query.value(rec.indexOf("price")).toDouble();
        qDebug() << "id is " << id
                 << ". to_country is " << toCountry
                 << ". from_country is " << fromCountry
                 << ". price" << price;
    }
    db.close();
}
