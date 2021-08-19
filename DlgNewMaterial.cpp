#include "DlgNewMaterial.h"
#include "ui_DlgNewMaterial.h"

DlgNewMaterial::DlgNewMaterial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewMaterial)
{
    ui->setupUi(this);
    setWindowTitle(QString("New Material"));

    ui->cB_materialModel->addItem("Linear Viscoelastic");
}

DlgNewMaterial::~DlgNewMaterial()
{
    delete ui;
}

void DlgNewMaterial::accept()
{
    QDialog::accept();
}
