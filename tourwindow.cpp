#include "tourwindow.h"
#include "ui_tourwindow.h"
#include <QDebug>

TourWindow::TourWindow(QWidget *parent, const QSqlDatabase &database) :
        QDialog(parent),
        ui(new Ui::TourWindow),
        database(database) {
    ui->setupUi(this);

    hostelController = new HostelController(database);
    flightController = new FlightController(database);

    ui->hostel_table_view->setModel(hostelController->findAll());
    ui->flight_table_view->setModel(flightController->findAll());
}

TourWindow::~TourWindow() {
    delete ui;
}

void TourWindow::on_cancel_clicked() {
    this->close();
    emit firstWindow();
}

void TourWindow::on_flight_table_view_doubleClicked(const QModelIndex &index) {
    qDebug() << "TourWindow  - flight and here we are";
    qDebug() << "id is: " << index.data();
    this->tour->setFlightId(index.data().toInt());
}

void TourWindow::on_hostel_table_view_doubleClicked(const QModelIndex &index) {
    qDebug() << "TourWindow  - hostel and here we are";
    qDebug() << "id is: " << index.data();
    this->tour->setHostelId(index.data().toInt());
}

void TourWindow::on_save_clicked() {
    QDate from = ui->date_from->date();
    QString dateString = from.toString();
    qDebug() << dateString;
    QDate to = ui->date_to->date();
    QString date = to.toString();
    qDebug() << date;

    //Days counter
    qDebug() << "There are " << from.daysTo(to) << endl;


    //user data
    QString name_text = ui->name_text->toPlainText();
    string name = name_text.toLocal8Bit().constData();

    QString surname_text = ui->surname_text->toPlainText();
    string surname = surname_text.toLocal8Bit().constData();

    QString phone_text = ui->phone_text->toPlainText();
    string phone = phone_text.toLocal8Bit().constData();

    int counter = ui->people_counter->value();

    qDebug() << "User is: " << name_text << surname_text << phone_text << counter << endl;

    //TODO: set all data to tour, show the cost and save to db by id;
}
