#include "basecontroller.h"

#include <iostream>
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

BaseController::BaseController(const QSqlDatabase &db) : db(db) {}

BaseController::~BaseController() {};

void BaseController::createTable(QString create_table_query) {
    db.open();
    if (!db.open()) {
        qDebug() << db.lastError().text();
        qDebug() << "cant open connection";
    }
    QSqlQuery query;
    bool successQuery = query.exec(create_table_query);
    if (!successQuery) {
        qDebug() << db.lastError() << endl;
        qDebug() << "cant create table!";
    } else {
        qDebug() << "created the table!";
    }
    db.close();
}

void BaseController::insert(QString insert_query) {
    db.open();
    QSqlQuery query;
    bool successQuery = query.exec(insert_query);
    if (!successQuery) {
        qDebug() << "Can't save the entity to database!";
    } else {
        qDebug() << "save the entity to database!";
    }
    db.close();
}

QSqlQueryModel *BaseController::findAll(QString select_query) {
    db.open();
    QSqlQuery query;
    QSqlQueryModel *modal = new QSqlQueryModel();

    if (!query.exec(select_query)) {
        qDebug() << "Select query doesn't work.";
    }

    modal->setQuery(query);

    db.close();
    return modal;
}
