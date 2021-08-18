#include "DlgNewMaterial.h"
#include "ui_DlgNewMaterial.h"

DlgNewMaterial::DlgNewMaterial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewMaterial)
{
    ui->setupUi(this);
    setWindowTitle(QString("New Material"));
}

DlgNewMaterial::~DlgNewMaterial()
{
    delete ui;
}
