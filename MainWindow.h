#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "DlgAbout.h"
#include "DlgNewMaterial.h"
#include "LinearViscoelasticMaterial.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class LinearViscoelasticMaterial;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void setActionsForTemperatureAndFrequency();

private slots:
    void on_pB_AddTemp_clicked();

    void on_pB_DeleteTemp_clicked();

    void on_pB_AddFreq_clicked();

    void on_pB_DeleteFreq_clicked();

private:
    Ui::MainWindow *ui;


    //FILE
    DlgNewMaterial *newMaterial = new DlgNewMaterial();

    //HELP
    QString version = QString(" 1.0.0");
    DlgAbout *about = new DlgAbout(version);

    //Materials
    LinearViscoelasticMaterial *pu;

};
#endif // MAINWINDOW_H
