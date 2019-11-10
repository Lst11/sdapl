#include "tourcontroller.h"
#include <string>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

using namespace std;

TourController::TourController(const QSqlDatabase &db) : BaseController(db) {
    createTable(create_tours_table_query);
}

void TourController::save(Tour *tour) {
    QString tour_to_insert = insert_tour_query.arg(QString::fromStdString(tour->getUser()->getName()))
            .arg(QString::fromStdString(tour->getUser()->getSurname()))
            .arg(QString::fromStdString(tour->getUser()->getPhone()))
            .arg(tour->getHostelId())
            .arg(tour->getFlightId())
            .arg(tour->getNightCounter())
            .arg(tour->getPersonCounter());

    insert(tour_to_insert);
}

QSqlQueryModel *TourController::findAll() {
    return BaseController::findAll(select_tours_query);
}

void TourController::showAll() {
    qDebug()<< "Show tours:";
    QSqlQueryModel *model = BaseController::findAll(select_tours_query);

    for (int i = 0; i < model->rowCount(); ++i) {
        QSqlRecord entity = model->record(i);

        int id = entity.value(0).toInt();
        QString userName = entity.value(1).toString();
        QString userSurname = entity.value(2).toString();
        QString userPhone = entity.value(3).toString();

        int hostelId = entity.value(4).toInt();
        int flightId = entity.value(5).toInt();
        int days = entity.value(6).toInt();
        int persons = entity.value(7).toInt();

        qDebug() << "id is " << id
                 << ". user name: " << userName
                 << ". user surname: " << userSurname
                 << ". user phone: " << userPhone
                 << ". hostelId is " << hostelId
                 << ". flightId is " << flightId
                 << ". days is: " << days
                 << ". persons" << persons;
    }
}
