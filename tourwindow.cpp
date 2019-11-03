#include "tourwindow.h"
#include "ui_tourwindow.h"

TourWindow::TourWindow(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::TourWindow) {
    ui->setupUi(this);
}

TourWindow::~TourWindow() {
    delete ui;
}

void TourWindow::on_cancel_clicked() {
    this->close();
    emit firstWindow();
}
