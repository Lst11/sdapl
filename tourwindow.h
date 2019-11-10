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

    void countPrice();

    void on_people_counter_valueChanged(int arg1);

    void on_date_from_userDateChanged(const QDate &date);

    void on_date_to_userDateChanged(const QDate &date);

private:
    Ui::TourWindow *ui;
    QSqlDatabase database;
    HostelController *hostelController;
    FlightController *flightController;
    TourController *tourController;
    Tour *tour = new Tour();

    int flightPriceToOneSide = 0;
    int hostelPricePerNight = 0;
    int personCounter = 0;
    int days = 0;
};

#endif // TOURWINDOW_H
