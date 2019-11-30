#include "hostelcontroller.h"
#include "Hostel.h"
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

HostelController::HostelController(const QSqlDatabase &db) : BaseController(db) {
    createTable(create_hostel_table_query);
}

void HostelController::save(Hostel *hostel) {
    QString hostel_to_insert = insert_hostel_query.arg(QString::fromStdString(hostel->getName()))
            .arg(hostel->getCostPerNight())
            .arg(QString::fromStdString(hostel->getCountry()))
            .arg(QString::fromStdString(hostel->getCity()));

    insert(hostel_to_insert);
}

QSqlQueryModel *HostelController::findAll() {
    return BaseController::findAll(select_hostels_query);
}

QSqlQueryModel *HostelController::findAllByCountry(string countryName) {
    QString search_query =
            "SELECT * FROM hostels WHERE hostel_country LIKE '" + QString::fromStdString(countryName) + "%'";

    return BaseController::findAll(search_query);
}

QSqlQueryModel *HostelController::findAllSortedByCountry() {
    QString search_query = "SELECT * FROM hostels ORDER BY hostel_country;";

    return BaseController::findAll(search_query);
}

QSqlQueryModel *HostelController::findAllSortedByPrice() {
    QString search_query = "SELECT * FROM hostels ORDER BY hostel_cost_per_night;";

    return BaseController::findAll(search_query);
}

Hostel *HostelController::findById(int hostelId) {
    QString select_hostel_by_id_query = find_by_id_hostel_query.arg(hostelId);
    QSqlQueryModel *model = BaseController::findAll(select_hostel_by_id_query);
    return convertToHostel(model->record(0));
}

void HostelController::showAll() {
    qDebug() << "Show hostels:";
    QSqlQueryModel *model = BaseController::findAll(select_hostels_query);

    for (int i = 0; i < model->rowCount(); ++i) {
        QSqlRecord entity = model->record(i);
        convertToHostel(entity);
    }
}


Hostel *HostelController::convertToHostel(QSqlRecord entity) {
    qDebug() << entity;
    int id = entity.value(0).toInt();
    QString name = entity.value(1).toString();
    int price = entity.value(2).toInt();
    QString country = entity.value(3).toString();
    QString city = entity.value(4).toString();
    return new Hostel(name.toLocal8Bit().constData(),
                      price,
                      country.toLocal8Bit().constData(),
                      city.toLocal8Bit().constData());
}
