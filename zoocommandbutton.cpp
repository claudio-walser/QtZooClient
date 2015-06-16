#include <QPushButton>
#include "zoocommandbutton.h"


ZooCommandButton::ZooCommandButton(QPushButton *parent) :
    QPushButton(parent)
{
    QObject::connect(this, SIGNAL(clicked()),this, SLOT(emitCommandClicked()));
}

void ZooCommandButton::emitCommandClicked()
{
    emit commandClicked(this->text());
}
