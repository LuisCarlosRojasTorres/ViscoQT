#include "DlgAbout.h"
#include "ui_DlgAbout.h"

DlgAbout::DlgAbout(QString version, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgAbout)
{
    ui->setupUi(this);
    setWindowTitle(QString("About"));

    QString text = QString(
                "ViscoQT" +version+" 2021 \n"
                " - Dev: Luis Carlos A. Rojas Torres\n"
                " - Email: redtower.soft@gmail.com\n"
                " - LinkedIn: luiscarlos-rojastorres-fem/"
    );
    ui->lbl_About->setText(text);
}

DlgAbout::~DlgAbout()
{
    delete ui;
}
