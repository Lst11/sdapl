#include "flightcontroller.h"
#include "flight.h"
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

FlightController::FlightController(const QSqlDatabase &db) : BaseController(db) {
    createTable(create_flight_table_query);
}

void FlightController::save(Flight *flight) {
    QString flight_to_insert = insert_flight_query.arg(QString::fromStdString(flight->getToCountry()))
            .arg(QString::fromStdString(flight->getFromCountry()))
            .arg(flight->getPrice());
    insert(flight_to_insert);
}

QSqlQueryModel *FlightController::findAll() {
    return BaseController::findAll(select_flights_query);
}

void FlightController::showAll() {
    qDebug()<< "Show flights:";
    QSqlQueryModel *model = BaseController::findAll(select_flights_query);

    for (int i = 0; i < model->rowCount(); ++i) {
        QSqlRecord entity = model->record(i);

        int id = entity.value(0).toInt();
        QString toCountry =  entity.value(1).toString();
        QString fromCountry = entity.value(2).toString();
        double price = entity.value(3).toDouble();

        qDebug() << "id is " << id
                 << ". to_country is " << toCountry
                 << ". from_country is " << fromCountry
                 << ". price" << price;
    }
}
