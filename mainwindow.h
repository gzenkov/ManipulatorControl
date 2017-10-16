#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelectionModel>
#include "linktablemodel.h"
#include "manipulatormodel.h"
#include "lineeditdelegate.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updatePosition();
    void resetResult();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

    linkTableModel *linksModel;
    ManipulatorModel *manModel;

    QItemSelectionModel *selection;

    Manipulator man;
};

#endif // MAINWINDOW_H
