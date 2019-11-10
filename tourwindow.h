#ifndef TOURWINDOW_H
#define TOURWINDOW_H

#include <QDialog>
#include <hostelcontroller.h>
#include <flightcontroller.h>
#include <tourcontroller.h>
#include "tour.h"

namespace Ui {
    class TourWindow;
}

class TourWindow : public QDialog {
    Q_OBJECT

public:
    TourWindow(QWidget *parent = nullptr, const QSqlDatabase &database = QSqlDatabase::database());

    ~TourWindow();

    signals:
            void

    firstWindow();

private
    slots:
            void

    on_cancel_clicked();

    void on_hostel_table_view_doubleClicked(const QModelIndex &index);

    void on_flight_table_view_doubleClicked(const QModelIndex &index);

    void on_save_clicked();

private:
    Ui::TourWindow *ui;
    QSqlDatabase database;
    HostelController *hostelController;
    FlightController *flightController;
    TourController *tourController;
    Tour *tour = new Tour();
    int fullPrice = 0;
};

#endif // TOURWINDOW_H
