#include "DlgNewMaterial.h"
#include "ui_DlgNewMaterial.h"

#include <QMessageBox>
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

void DlgNewMaterial::setViscousTableFromVectors(std::vector<double> gi, std::vector<double> Taui)
{
    for(int i = 0; i < gi.size(); i++){
        dummyItem = new QTableWidgetItem(QString::number(gi.at(i)));
        ui->viscousTableWidget->setItem(i,0,dummyItem);
        dummyItem = new QTableWidgetItem(QString::number(Taui.at(i)));
        ui->viscousTableWidget->setItem(i,1,dummyItem);
    }
}

void DlgNewMaterial::elasticDataValidator()
{
    //Tem que ser maior do que ZERO
    //O rango de valores possíveis esta determinado na GUI
    if(ui->dSB_ElasticModulus->value() == 0){
        isValidMaterial = false;
    }
}

void DlgNewMaterial::viscousDataValidator()
{

}

void DlgNewMaterial::wlfDataValidator()
{
    if( ( ui->dSB_Tref ->value()== 0) ||
        ( ui->dSB_c1 ->value()== 0) ||
        ( ui->dSB_c2 ->value()== 0)
    ){
        isValidMaterial = false;
    }

}

void DlgNewMaterial::accept()
{
    elasticDataValidator();
    viscousDataValidator();
    wlfDataValidator();

    if(isValidMaterial){
        QDialog::accept();
    }
    else{

        QMessageBox::warning(this, tr("New Material"),
                                       tr("Invalid material!.\n"
                                          "Zero values in input data"));
    }

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
        ui->viscousTableWidget->clearContents();
        ui->sB_numOfTerms->setValue(1);

    }else{
        std::cout << "DlgNewMaterial::setVISCOUSDefault(TRUE)" << std::endl;
        ui->sB_numOfTerms->setValue(8);
        setViscousTableFromVectors(gi, Taui);

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
