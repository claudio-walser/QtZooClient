#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>

namespace Ui {
class MenuBar;
}

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = 0);
    ~MenuBar();

private:
    Ui::MenuBar *ui;
};

#endif // MENUBAR_H


