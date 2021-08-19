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
};

#endif // DLGNEWMATERIAL_H
