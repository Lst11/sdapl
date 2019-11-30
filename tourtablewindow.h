#ifndef TOURTABLEWINDOW_H
#define TOURTABLEWINDOW_H

#include <QDialog>
#include <QTableView>
#include <tourcontroller.h>

namespace Ui {
class TourTableWindow;
}

class TourTableWindow : public QDialog
{
    Q_OBJECT

public:
    TourTableWindow(QWidget *parent = nullptr, const QSqlDatabase &database = QSqlDatabase::database());

    ~TourTableWindow();

    signals:
            void

    firstWindow();

private
    slots:
            void on_cancel_button_clicked();

private:
    Ui::TourTableWindow *ui;
    QSqlDatabase database;
    TourController *tourController;
};

#endif // TOURTABLEWINDOW_H
