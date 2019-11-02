#include "hostelcontroller.h"
#include "Hostel.h"
#include <iostream>
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

HostelController::HostelController() {
    createTableHostel();
}

void HostelController::createTableHostel() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("db_name.sqlite");
    db.open();

    if (!db.open()) {
        qDebug() << db.lastError().text();
    }

    QSqlQuery query;
    bool successQuery = query.exec(create_hostel_table_query);
    if (!successQuery) {
        qDebug() << "Can't create a table!";
    }
}

void HostelController::save(Hostel *hostel) {
    QString hostel_to_insert = insert_hostel_query.arg(QString::fromStdString(hostel->getName()))
            .arg(hostel->getCostPerNight())
            .arg(QString::fromStdString(hostel->getCountry()))
            .arg(QString::fromStdString(hostel->getCity()));
    QSqlQuery query;
    bool successQuery = query.exec(hostel_to_insert);
    if (!successQuery) {
        qDebug() << "Can't save the hostel to database!";
    }
}

void HostelController::findAll() {
    //TODO: save to list;
}

void HostelController::showAll() {
    QSqlQuery query;

    if (!query.exec("SELECT * FROM hostels")) {
        qDebug() << "Select query doesn't work.";
    }
    QSqlRecord rec = query.record();

    while (query.next()) {
        int number = query.value(rec.indexOf("number")).toInt();
        QString name = query.value(rec.indexOf("name")).toString();
        int price = query.value(rec.indexOf("cost_per_night")).toInt();
        QString country = query.value(rec.indexOf("country")).toString();
        QString city = query.value(rec.indexOf("city")).toString();
        qDebug() << "number is " << number
                 << ". age is " << name
                 << ". price is " << price
                 << ". country" << country
                 << ". city" << city;
    }
}
