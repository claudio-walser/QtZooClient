#ifndef ZOOIALOG_H
#define ZOODIALOG_H

#include <QDialog>

namespace Ui {
class ZooDialog;
}

class ZooDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZooDialog(QWidget *parent = 0);
    ~ZooDialog();
    QString getServerAdress();

private:
    Ui::ZooDialog *ui;
};

#endif // ZOODIALOG_H

