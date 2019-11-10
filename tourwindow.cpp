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
    tourController = new TourController(database);


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
    QDate to = ui->date_to->date();
    QString date = to.toString();

    //Days counter
    qDebug() << "There are " << from.daysTo(to) << endl;
    int days = from.daysTo(to);

    //user data
    QString name_text = ui->name_text->toPlainText();
    string name = name_text.toLocal8Bit().constData();

    QString surname_text = ui->surname_text->toPlainText();
    string surname = surname_text.toLocal8Bit().constData();

    QString phone_text = ui->phone_text->toPlainText();
    string phone = phone_text.toLocal8Bit().constData();

    int counter = ui->people_counter->value();

    if (name.empty() || surname.empty() || phone.empty() || counter <= 0 || days <= 0L) {
        ui->tour_label->setText("Input error! The fields must contain data!");
    } else {
        ui->tour_label->setText("");

        User *user = new User(name, surname, phone);
        tour->setUser(user);
        tour->setNightCounter(days);
        tour->setPersonCounter(counter);
        qDebug() << tour;

        tourController->save(tour);
        tourController->showAll();

    }
    //TODO:show the cost;
}

void TourWindow::countPrice() {
    int fullPrice = personCounter * days;
    ui->price_info->setText(QString::number(fullPrice));
}

void TourWindow::on_people_counter_valueChanged(int arg1) {
    personCounter = ui->people_counter->value();
    countPrice();
}

void TourWindow::on_date_from_userDateChanged(const QDate &date) {
    QDate from = ui->date_from->date();
    QDate to = ui->date_to->date();

    days = from.daysTo(to);
    countPrice();
}

void TourWindow::on_date_to_userDateChanged(const QDate &date) {
    QDate from = ui->date_from->date();
    QDate to = ui->date_to->date();

    days = from.daysTo(to);
    countPrice();
}
