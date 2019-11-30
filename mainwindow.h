#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <hostelcontroller.h>
#include <tourwindow.h>
#include <tourtablewindow.h>
#include <flightcontroller.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private
    slots:

            void

    on_search_clicked();

    void on_save_hostel_clicked();

    void on_save_flight_clicked();

    void on_create_tour_clicked();

    void on_sort_by_price_clicked();

    void on_sort_by_country_clicked();

    void on_table_view_doubleClicked(const QModelIndex &index);

    void on_show_tours_clicked();

private:
    Ui::MainWindow *ui;
    TourWindow *secondWindow;
    TourTableWindow *thirdWindow;
    QSqlDatabase db;
    HostelController *hostelController;
    FlightController *flightController;
};
#endif // MAINWINDOW_H
