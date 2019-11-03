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

HostelController::HostelController(const QSqlDatabase &db) : db(db)
{
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
        qDebug() << "cant create table hostel!";
    } else {
        qDebug() << "created the table hostel!";
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
    } else{
        qDebug() << "save the hostel to database!";
    }
    db.close();
}

QSqlQueryModel* HostelController::findAllByPrice() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel * modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM hostel ORDER BY cost_per_night;")) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

QSqlQueryModel* HostelController::findAll() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel * modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM hostel")) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

QSqlQueryModel* HostelController::findAllByCountry() {
    db.open();
    QSqlQuery query;
    QSqlQueryModel * modal = new QSqlQueryModel();

    if (!query.exec("SELECT * FROM hostel ORDER BY country;")) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);
    qDebug() << modal->rowCount();

    db.close();

    return modal;
}

void HostelController::showAll() {
    db.open();
    QSqlQuery query;

    if (!query.exec("SELECT * FROM hostel")) {
        qDebug() << "Select query doesn't work.";
    }
    QSqlRecord rec = query.record();

    while (query.next()) {
        int id = query.value(rec.indexOf("id")).toInt();
        QString name = query.value(rec.indexOf("name")).toString();
        int price = query.value(rec.indexOf("cost_per_night")).toInt();
        QString country = query.value(rec.indexOf("country")).toString();
        QString city = query.value(rec.indexOf("city")).toString();
        qDebug() << "id is " << id
                 << ". age is " << name
                 << ". price is " << price
                 << ". country" << country
                 << ". city" << city;
    }
    db.close();
}
