#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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
};
#endif // MAINWINDOW_H