#ifndef DLGNEWMATERIAL_H
#define DLGNEWMATERIAL_H

#include <QDialog>

namespace Ui {
class DlgNewMaterial;
}

class DlgNewMaterial : public QDialog
{
    Q_OBJECT

public:
    explicit DlgNewMaterial(QWidget *parent = nullptr);
    ~DlgNewMaterial();

private:
    Ui::DlgNewMaterial *ui;
};

#endif // DLGNEWMATERIAL_H
