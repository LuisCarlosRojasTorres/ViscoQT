#ifndef DLGNEWMATERIAL_H
#define DLGNEWMATERIAL_H

#include <QDialog>

namespace Ui {
class DlgNewMaterial;
}

class QTableWidgetItem;

class DlgNewMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewMaterial(QWidget *parent = nullptr);
    ~DlgNewMaterial();

    void removeRows();
    void setViscousTableFromVectors(std::vector<double> gi,std::vector<double> Taui);


    //Ao apertar ACCEPT primeiro tem que validar os dados elastic, a viscousTab e os parametros WLF
    //se qualquer um da false a variavel isValidMaterial = false
    void validateElasticData();
    void validateViscousData();
    void validateWLFData();

public slots:
    virtual void accept();

    void setElasticDefault(int index);

    void setRows(int index);
    void setViscousDefault(int index);

    void setWLFDefault(int index);

private:
    Ui::DlgNewMaterial *ui;

    int currentNumOfRows = 1;
    QTableWidgetItem *dummyItem; //Para viscousTableWidget
    bool isValidMaterial = true;

    //TODO: Estes vetores devem ser substituidos por um objeto do tipo LinearViscoelastic
    std::vector<double> gi = {0.1972,0.1403,0.0971,0.0706,0.05,0.0333,0.0206,0.0176};
    std::vector<double> Taui = {0.581,3.13,18.8,125,1040,10900,160000,5220000};

};

#endif // DLGNEWMATERIAL_H
