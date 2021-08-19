#include "DlgNewMaterial.h"
#include "ui_DlgNewMaterial.h"

#include <QStringLiteral>
#include <iostream>

DlgNewMaterial::DlgNewMaterial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DlgNewMaterial)
{
    ui->setupUi(this);
    setWindowTitle(QString("New Material"));

    ui->cB_materialModel->addItem("Linear Viscoelastic");

//>> ELASTIC TAB
    connect(ui->checkBox_ElasticDefault, &QCheckBox::stateChanged,
            this, &DlgNewMaterial::setElasticDefault);

//>> VISCOUS TAB
    const QStringList headers = {
        QStringLiteral("gi [MPa/MPa]"),
        QStringLiteral("Rel. Times [s]")
    };

    //Permite que as colunas da tabela ocupem o espaco todo
    ui->viscousTableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->viscousTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //Seta o numero de colunas em 2 e o nome dos cabeçalhos
    ui->viscousTableWidget->setColumnCount(2);
    ui->viscousTableWidget->setHorizontalHeaderLabels(headers);

    //insere a primeira fila e connecta o spinbox com o numero de filas
    ui->viscousTableWidget->insertRow(currentNumOfRows-1);
    connect(ui->sB_numOfTerms, QOverload<int>::of(&QSpinBox::valueChanged),
            this,&DlgNewMaterial::setRows);

    //Seta os valores do PU do artigo, ou limpa todos os valores
    connect(ui->checkBox_ViscousDefault, &QCheckBox::stateChanged,
            this, &DlgNewMaterial::setViscousDefault);


//>> WLF TAB
    //Seta os valores do PU do artigo, ou limpa todos os valores
    connect(ui->checkBox_WLFDefault, &QCheckBox::stateChanged,
            this, &DlgNewMaterial::setWLFDefault);

}

DlgNewMaterial::~DlgNewMaterial()
{
    delete ui;
}

void DlgNewMaterial::accept()
{
    QDialog::accept();
}

void DlgNewMaterial::setElasticDefault(int index)
{
    if(index == 0){
        std::cout << "DlgNewMaterial::setELASTICDefault(FALSE)" << std::endl;
        ui->dSB_ElasticModulus->setValue(0);
    }else{
        std::cout << "DlgNewMaterial::setELASTICDefault(TRUE)" << std::endl;
        ui->dSB_ElasticModulus->setValue(101.9);
    }
}

void DlgNewMaterial::setRows(int index)
{
    if(index > currentNumOfRows){
        while(index> currentNumOfRows){
            ui->viscousTableWidget->insertRow(currentNumOfRows);
            currentNumOfRows++;
        }
    }

    if(index < currentNumOfRows){
        while(index < currentNumOfRows){
            ui->viscousTableWidget->removeRow(currentNumOfRows-1);
            currentNumOfRows--;
        }
    }

}

void DlgNewMaterial::setViscousDefault(int index)
{
    //TODO: Precisa ser refatorado!!!, fiz priorizando funcionalidade...
    if(index == 0){
        std::cout << "DlgNewMaterial::setVISCOUSDefault(FALSE)" << std::endl;
        //ui->viscousTableWidget->insertRow(currentNumOfRows-1);
//        dummyItem = new QTableWidgetItem(QString("111"));
//        ui->viscousTableWidget->setItem(0,0,dummyItem);
//        dummyItem = new QTableWidgetItem(QString("222"));
//        ui->viscousTableWidget->setItem(0,1,dummyItem);
//        dummyItem = new QTableWidgetItem(QString("111"));
//        ui->viscousTableWidget->setItem(1,0,dummyItem);
//        dummyItem = new QTableWidgetItem(QString("222"));
//        ui->viscousTableWidget->setItem(1,1,dummyItem);

    }else{
        std::cout << "DlgNewMaterial::setVISCOUSDefault(TRUE)" << std::endl;
//        dummyItem = new QTableWidgetItem(QString("0.1972"));
//        ui->viscousTableWidget->setItem(0,0,dummyItem);
//        dummyItem = new QTableWidgetItem(QString("0.581"));
//        ui->viscousTableWidget->setItem(0,1,dummyItem);

//        ui->viscousTableWidget->insertRow(1);
//        dummyItem = new QTableWidgetItem(QString("0.1972"));
//        ui->viscousTableWidget->setItem(1,0,dummyItem);
//        dummyItem = new QTableWidgetItem(QString("0.581"));
//        ui->viscousTableWidget->setItem(1,1,dummyItem);

    }
}

void DlgNewMaterial::setWLFDefault(int index)
{
    if(index == 0){
        std::cout << "DlgNewMaterial::setWLFDefault(FALSE)" << std::endl;
        ui->dSB_c1->setValue(0);
        ui->dSB_c2->setValue(0);
        ui->dSB_Tref->setValue(0);
    }else{
        std::cout << "DlgNewMaterial::setWLFDefault(TRUE)" << std::endl;
        ui->dSB_c1->setValue(7.32);
        ui->dSB_c2->setValue(93.62);
        ui->dSB_Tref->setValue(23);
    }
}
