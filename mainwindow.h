#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string>
#include <hostelcontroller.h>
#include <flightcontroller.h>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

private
    slots:
            void

    on_search_clicked();

    void on_save_hostel_clicked();

    //string convertToChar(QString text);

    void on_save_flight_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    HostelController *hostelController;
    FlightController *flightController;
};
#endif // MAINWINDOW_H
