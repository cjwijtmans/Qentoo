#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QFile>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTreeWidgetItem* tiPortage = new QTreeWidgetItem(QStringList("Portage"));
    ui->treeWidget->addTopLevelItem(tiPortage);
    QFile fCats("/usr/portage/profiles/categories");
    fCats.open(QIODevice::ReadOnly);
    QTextStream tsCats(&fCats);
    while(!tsCats.atEnd())
        ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(tiPortage, QStringList(tsCats.readLine())));
}

MainWindow::~MainWindow()
{
    delete ui;
}
