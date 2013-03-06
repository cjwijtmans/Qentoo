#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QProcess>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    QProcess process;
    process.start("emerge --info", QIODevice::ReadOnly);
    QTextStream info(process.readAllStandardOutput());
    while(!info.atEnd())
    {
        QString str = info.readLine();
        QStringList strls = str.split('=', QString::SkipEmptyParts);

    }

    ui->setupUi(this);
    //QTreeWidgetItem* tiGentoo = new QTreeWidgetItem(QStringList(gentoo.getName()));
    //ui->treeWidget->addTopLevelItem(tiGentoo);
    //gentoo.getCategories();
    connect(ui->treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(categoryChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::categoryChanged()
{
    QTreeWidgetItem* selected = ui->treeWidget->selectedItems().first();
    if(selected && selected->parent())
    {
        selected->text(0);
        selected->parent()->text(0);
    }
}
