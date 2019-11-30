#include "tourtablewindow.h"
#include "ui_tourtablewindow.h"
#include <QDebug>

using namespace std;

TourTableWindow::TourTableWindow(QWidget *parent, const QSqlDatabase &database) :
        QDialog(parent),
        ui(new Ui::TourTableWindow),
        database(database) {
    ui->setupUi(this);

    tourController = new TourController(database);

    ui->tour_table_view->setModel(tourController->findAll());
}

TourTableWindow::~TourTableWindow() {
    delete ui;
}

void TourTableWindow::on_cancel_button_clicked() {
    this->close();
    emit firstWindow();
}
