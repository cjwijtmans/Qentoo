#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(categoryChanged()));

    for(Repositories::const_iterator iter = m_Portage.getRepositories().constBegin(); iter != m_Portage.getRepositories().constEnd(); ++iter)
    {
        QTreeWidgetItem* twItem = new QTreeWidgetItem(QStringList(iter->getName()));
        ui->treeWidget->addTopLevelItem(twItem);
        auto setCategories = iter->getCategories();
        for(auto sub_iter = setCategories.begin(); sub_iter != setCategories.end(); ++sub_iter)
        {
            QTreeWidgetItem* twSubItem = new QTreeWidgetItem(twItem, QStringList(*sub_iter));
            ui->treeWidget->addTopLevelItem(twSubItem);
        }
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::categoryChanged()
{
    QTreeWidgetItem* selected = ui->treeWidget->selectedItems().first();
    if(selected && selected->parent() && m_Portage.getRepositories().contains(selected->parent()->text(0)))
    {
        QStringList strlPackages = m_Portage.getRepository(selected->parent()->text(0)).getPackages(selected->text(0));
        ui->tableWidget->setRowCount(strlPackages.length());
        for(QStringList::iterator iter = strlPackages.begin(); iter != strlPackages.end(); ++iter)
        {
            ui->tableWidget->setItem((strlPackages.end() - iter) - 1, 0, new QTableWidgetItem(*iter));
        }
    }
}
