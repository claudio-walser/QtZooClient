#ifndef ZOOCOMMANDBUTTON_H
#define ZOOCOMMANDBUTTON_H
#include <QPushButton>


class ZooCommandButton : public QPushButton
{
    Q_OBJECT

public:
    explicit ZooCommandButton(QPushButton *parent = 0);
    ~ZooCommandButton();



signals:
   void commandClicked(QString command);

private slots:
   void emitCommandClicked();

};

#endif // ZOOCOMMANDBUTTON_H
