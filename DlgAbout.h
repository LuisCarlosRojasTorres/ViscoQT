#ifndef DLGABOUT_H
#define DLGABOUT_H

#include <QDialog>

namespace Ui {
class DlgAbout;
}

class DlgAbout : public QDialog
{
    Q_OBJECT

public:
    explicit DlgAbout(QString version, QWidget *parent = nullptr);
    ~DlgAbout();

private:
    Ui::DlgAbout *ui;
};

#endif // DLGABOUT_H
