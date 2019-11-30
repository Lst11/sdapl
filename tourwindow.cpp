#include "tourwindow.h"
#include "ui_tourwindow.h"
#include <QDebug>

using namespace std;

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
    int item_id = find_id_from_table(index, ui->flight_table_view);
    this->tour->setFlightId(item_id);
    countPrice();
}

void TourWindow::on_hostel_table_view_doubleClicked(const QModelIndex &index) {
    qDebug() << "TourWindow  - hostel and here we are";

    int item_id = find_id_from_table(index, ui->hostel_table_view);
    this->tour->setHostelId(item_id);
    countPrice();
}

void TourWindow::on_save_clicked() {
    QDate from = ui->date_from->date();
    QString dateString = from.toString();
    QDate to = ui->date_to->date();
    QString date = to.toString();

    //Days counter;
    qDebug() << "There are " << from.daysTo(to) << endl;
    int days = from.daysTo(to);

    //Customer data;
    QString name_text = ui->name_text->toPlainText();
    string name = name_text.toLocal8Bit().constData();

    QString surname_text = ui->surname_text->toPlainText();
    string surname = surname_text.toLocal8Bit().constData();

    QString phone_text = ui->phone_text->toPlainText();
    string phone = phone_text.toLocal8Bit().constData();

    int counter = ui->people_counter->value();

    if (tour->getHostelId() == 0 || name.empty() || surname.empty() || phone.empty() || counter <= 0 || days <= 0L) {
        ui->tour_label->setText("Input error! The fields must contain data and at least hostel should be selected!");
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
}

void TourWindow::countPrice() {
    qDebug() << "Counting price";

    int flightPrice = 0;
    if(tour->getFlightId() > 0 ){
        Flight  *flight = flightController ->findById(tour->getFlightId());
        flightPrice = flight -> getPrice();
    }

    int hostelPrice = 0;
    if(tour->getHostelId() > 0 ){
        qDebug() << "Counting price";
        Hostel  *hostel = hostelController ->findById(tour->getHostelId());
        hostelPrice = hostel -> getCostPerNight();
    }

    int fullPrice = personCounter * (days * hostelPrice + flightPrice);
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

int TourWindow::find_id_from_table(const QModelIndex &index, QTableView *tableView){
    QItemSelectionModel * selectModel = tableView ->selectionModel();
    QModelIndexList indexes = selectModel->selectedIndexes();
    for(auto index : indexes){
        int row = index.row();
        QString tmp = tableView->model()->data(tableView->model()->index(row,0)).toString();
        if ( row != -1 )
        {
            qDebug() << "id is: " << tmp;
            return tmp.toInt();
        }
        break;
    }
}
