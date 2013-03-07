#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeWidget, SIGNAL(itemSelectionChanged()), this, SLOT(categoryChanged()));

    for(Portage::Repositories::const_iterator iter = m_Portage.getRepositories().constBegin(); iter != m_Portage.getRepositories().constEnd(); ++iter)
    {
        QTreeWidgetItem* twItem = new QTreeWidgetItem(QStringList(iter->getName()));
        ui->treeWidget->addTopLevelItem(twItem);
        Repository::Categories setCategories = iter->getCategories();
        for(Portage::Categories::const_iterator sub_iter = setCategories.constBegin(); sub_iter != setCategories.constEnd(); ++sub_iter)
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
        Portage::Packages strlPackages = m_Portage.getRepository(selected->parent()->text(0)).getPackages(selected->text(0));
        ui->tableWidget->setRowCount(strlPackages.count());
        ui->tableWidget->setCurrentCell(0, 0);
        for(Portage::Packages::const_iterator iter = strlPackages.constBegin(); iter != strlPackages.constEnd(); ++iter)
        {
            ui->tableWidget->setItem(ui->tableWidget->currentRow(), 0, new QTableWidgetItem(*iter));
            ui->tableWidget->setCurrentCell(ui->tableWidget->currentRow() + 1, 0);
        }
    }
}
