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

HostelController::HostelController(const QSqlDatabase &db) : db(db) {
    createTableHostel();
}

void HostelController::createTableHostel() {
    db.open();
    if (!db.open()) {
        qDebug() << db.lastError().text();
        qDebug() << "cant open connection";
    }
    QSqlQuery query;
    bool successQuery = query.exec(create_hostel_table_query);
    if (!successQuery) {
        qDebug() << db.lastError() << endl;
        qDebug() << "cant create table hostels!";
    } else {
        qDebug() << "created the table hostels!";
    }
    db.close();
}

void HostelController::save(Hostel *hostel) {
    db.open();
    QString hostel_to_insert = insert_hostel_query.arg(QString::fromStdString(hostel->getName()))
            .arg(hostel->getCostPerNight())
            .arg(QString::fromStdString(hostel->getCountry()))
            .arg(QString::fromStdString(hostel->getCity()));
    QSqlQuery query;
    bool successQuery = query.exec(hostel_to_insert);
    if (!successQuery) {
        qDebug() << "Can't save the hostel to database!";
    } else {
        qDebug() << "save the hostel to database!";
    }
    db.close();
}

QSqlQueryModel *HostelController::findAll() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM hostels")) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

QSqlQueryModel *HostelController::findAllByCountry(string countryName) {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    QString search_query =
            "SELECT * FROM hostels WHERE hostel_country LIKE '" + QString::fromStdString(countryName) + "%'";
    if (!query.exec(search_query)) {
        qDebug() << "Select query by country doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

QSqlQueryModel *HostelController::findAllSortedByCountry() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM hostels ORDER BY hostel_country;")) {
        qDebug() << "Select query with sort by country doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

QSqlQueryModel *HostelController::findAllSortedByPrice() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM hostels ORDER BY hostel_cost_per_night;")) {
        qDebug() << "Select query with sort by price doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

void HostelController::showAll() {
    db.open();
    QSqlQuery query;

    if (!query.exec("SELECT * FROM hostels")) {
        qDebug() << "Select query doesn't work.";
    }
    QSqlRecord rec = query.record();

    while (query.next()) {
        int id = query.value(rec.indexOf("hostel_id")).toInt();
        QString name = query.value(rec.indexOf("hostel_name")).toString();
        int price = query.value(rec.indexOf("hostel_cost_per_night")).toInt();
        QString country = query.value(rec.indexOf("hostel_country")).toString();
        QString city = query.value(rec.indexOf("hostel_city")).toString();
        qDebug() << "id is " << id
                 << ". age is " << name
                 << ". price is " << price
                 << ". country" << country
                 << ". city" << city;
    }
    db.close();
}
