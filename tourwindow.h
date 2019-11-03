#ifndef TOURWINDOW_H
#define TOURWINDOW_H

#include <QDialog>

namespace Ui {
    class TourWindow;
}

class TourWindow : public QDialog {
    Q_OBJECT

public:
    explicit TourWindow(QWidget *parent = nullptr);

    ~TourWindow();

    signals:
            void

    firstWindow();

private
    slots:

            void

    on_cancel_clicked();

private:
    Ui::TourWindow *ui;

};

#endif // TOURWINDOW_H
