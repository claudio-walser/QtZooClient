#include "menubar.h"
#include "ui_menubar.h"
#include <QMenuBar>

MenuBar::MenuBar(QWidget *parent) :
    QMenuBar(parent),
    ui(new Ui::MenuBar)
{
    ui->setupUi(this);

}

MenuBar::~MenuBar()
{
    delete ui;
}
