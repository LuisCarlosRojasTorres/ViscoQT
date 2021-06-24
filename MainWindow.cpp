#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "LinearViscoelasticMaterial.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setActionsForTemperatureAndFrequency();

    pu = new LinearViscoelasticMaterial();

    std::cout << "Ep: " << pu->getStorageModulus(20,0.05) << std::endl;
    std::cout << "Epp: " << pu->getLossModulus(20,0.05) << std::endl;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setActionsForTemperatureAndFrequency()
{
    QAction *addTemp,*deleteTemp;
    addTemp = new QAction("Add Temperature",this);
    deleteTemp = new QAction("Delete Temperature",this);
    ui->listWidgetTemp->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->listWidgetTemp->addAction(addTemp);
    ui->listWidgetTemp->addAction(deleteTemp);

    connect(addTemp, SIGNAL(triggered()), this, SLOT(on_pB_AddTemp_clicked()));
    connect(deleteTemp, SIGNAL(triggered()), this, SLOT(on_pB_DeleteTemp_clicked()));

    QAction *addFreq,*deleteFreq;
    addFreq = new QAction("Add Frequency",this);
    deleteFreq = new QAction("Delete Frequency",this);
    ui->listWidgetFreq->setContextMenuPolicy(Qt::ActionsContextMenu);
    ui->listWidgetFreq->addAction(addFreq);
    ui->listWidgetFreq->addAction(deleteFreq);

    connect(addFreq, SIGNAL(triggered()), this, SLOT(on_pB_AddTempFreq_clicked()));
    connect(deleteFreq, SIGNAL(triggered()), this, SLOT(on_pB_DeleteFreq_clicked()));
}

void MainWindow::on_pB_AddTemp_clicked()
{
    QString temperature;
    temperature = ui->lineEditTemp->text();
    ui->listWidgetTemp->addItem(temperature);
}


void MainWindow::on_pB_DeleteTemp_clicked()
{
    delete ui->listWidgetTemp->currentItem();
}


void MainWindow::on_pB_AddFreq_clicked()
{
    QString frequency;
    frequency = ui->lineEditFreq->text();
    ui->listWidgetFreq->addItem(frequency);
}


void MainWindow::on_pB_DeleteFreq_clicked()
{
    delete ui->listWidgetFreq->currentItem();
}

