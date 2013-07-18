#include "MainWindow.hpp"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeCategories, SIGNAL(itemSelectionChanged()), this, SLOT(categoryChanged()));
    connect(ui->treeCategories, SIGNAL(itemExpanded(QTreeWidgetItem*)), this, SLOT(repositoryExpanded(QTreeWidgetItem*)));

    ui->treeCategories->clear();
    for(Portage::Repositories::const_iterator iter = m_Portage.getRepositories().constBegin(); iter != m_Portage.getRepositories().constEnd(); ++iter)
    {
        QTreeWidgetItem* twItem = new QTreeWidgetItem(QStringList(iter->getName()));
        twItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
        ui->treeCategories->addTopLevelItem(twItem);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::categoryChanged()
{
    QTreeWidgetItem* selected = ui->treeCategories->selectedItems().first();
    if(selected->parent())
    {
        Portage::Packages packages = m_Portage.getRepository(selected->parent()->text(0)).getPackages(selected->text(0));
        ui->treePackages->clear();
        for(Portage::Packages::const_iterator iter = packages.constBegin(); iter != packages.constEnd(); ++iter)
        {
            QTreeWidgetItem* twItem = new QTreeWidgetItem();
            twItem->setText(1, *iter);
            twItem->setChildIndicatorPolicy(QTreeWidgetItem::ShowIndicator);
            ui->treePackages->addTopLevelItem(twItem);
        }
    }
    else
    {
        //selected->setSelected(false);
    }
}

void MainWindow::repositoryExpanded(QTreeWidgetItem * item)
{
    if(item->childCount() == 0)
    {
        Repository::Categories setCategories = m_Portage.getRepository(item->text(0)).getCategories();
        for(Portage::Categories::const_iterator sub_iter = setCategories.constBegin(); sub_iter != setCategories.constEnd(); ++sub_iter)
        {
            QTreeWidgetItem* twSubItem = new QTreeWidgetItem(item, QStringList(*sub_iter));
            ui->treeCategories->addTopLevelItem(twSubItem);
        }
    }
}
