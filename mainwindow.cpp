#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    linksModel = new linkTableModel(&man,this);
    ui->tableView->setModel(linksModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    LineEditDelegate *del = new LineEditDelegate(ui->tableView);
    ui->tableView->setItemDelegate(del);

    manModel = new ManipulatorModel(&man,this);
    ui->tableView_2->setModel(manModel);
    ui->tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    selection = ui->tableView->selectionModel();

    connect(linksModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), manModel, SLOT(resetModel()));
    connect(linksModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(resetResult()));
    connect(manModel, SIGNAL(dataChanged(QModelIndex,QModelIndex,QVector<int>)), this, SLOT(updatePosition()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updatePosition()
{
    ui->label_8->setText(QString::number(man.recentPosition[0],'g',4));
    ui->label_9->setText(QString::number(man.recentPosition[1],'g',4));
    ui->label_10->setText(QString::number(man.recentPosition[2],'g',4));
}

void MainWindow::resetResult()
{
    ui->label_8->setText("--");
    ui->label_9->setText("--");
    ui->label_10->setText("--");
}

void MainWindow::on_pushButton_2_clicked()
{
    qint8 temp = selection->currentIndex().row();
    if (temp != -1)
        linksModel->insertRow(temp);
    else
        linksModel->insertRow(0);

    manModel->resetModel();

    resetResult();
}

void MainWindow::on_pushButton_clicked()
{
    qint8 temp = selection->currentIndex().row();
    if (temp != -1)
        linksModel->removeRow(temp);

    manModel->resetModel();

    resetResult();
}
