#include "mainwindow.h"
#include "ui_mainwindow.h"
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

MainWindow::MainWindow(QWidget *parent)
        : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    hostelController = new HostelController();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_save_hostel_clicked() {
    QString name_text = ui->hostel_name->toPlainText();
    string name = name_text.toLocal8Bit().constData();

    QString country_text = ui->hostel_country->toPlainText();
    string country = country_text.toLocal8Bit().constData();

    QString city_text = ui->hostel_city->toPlainText();
    string city = city_text.toLocal8Bit().constData();

    int price = ui->hostel_price->value();

    if (name.empty() || country.empty() || city.empty() || price <= 0) {
        ui->hotel_label->setText("Input error! The fields must contain data!");
    } else {
        ui->hotel_label->setText("");
        Hostel *hostel = new Hostel(name, price, country, city);
        hostel->show();

        hostelController->save(hostel);
        hostelController->showAll();
    }
}

//string MainWindow::convertToChar(QString text)
//{
//}

void MainWindow::on_search_clicked() {

}
