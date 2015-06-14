#ifndef MENUBAR_H
#define MENUBAR_H

#include <QMenuBar>
#include <QMainWindow>
#include "zootabs.h"

namespace Ui {
class MenuBar;
}

class MenuBar : public QMenuBar
{
    Q_OBJECT

public:
    explicit MenuBar(QWidget *parent = 0);
    ~MenuBar();
    void initializeActions();
    void setTabView(ZooTabs *zooServerContainer);

private slots:
    void openZooDialog();

private:
    Ui::MenuBar *ui;
    QAction *newZooAction;
    QMenu *newZooMenu;
    ZooTabs *tabView;
};


#endif // MENUBAR_H


