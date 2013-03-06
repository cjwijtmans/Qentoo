#include "MainWindow.hpp"
#include "ui_MainWindow.h"

#include <QProcess>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    :QMainWindow(parent)
    ,ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QProcess process;
    process.start("emerge --info", QProcess::ReadOnly);
    process.waitForFinished();
    QTextStream info(process.readAllStandardOutput());
    while(!info.atEnd())
    {
        QString str = info.readLine();
        m_Info.insert(str.section('=', 0, 0, QString::SectionSkipEmpty), str.section('"', 1, 1, QString::SectionSkipEmpty));
    }

    QStringList strlRepositories = m_Info.value("PORTDIR_OVERLAY").split(' ', QString::SkipEmptyParts);
    strlRepositories.append(m_Info.value("PORTDIR"));
    for(QStringList::const_iterator iter = strlRepositories.begin(); iter != strlRepositories.end(); ++iter)
    {
        Repository item(*iter);
        m_Repositories.insert(item.getName(), item);
        QTreeWidgetItem* twItem = new QTreeWidgetItem(QStringList(item.getName()));
        ui->treeWidget->addTopLevelItem(twItem);
        QStringList strlCategories = item.getCategories();
        for(QStringList::const_iterator sub_iter = strlCategories.begin(); sub_iter != strlCategories.end(); ++sub_iter)
        {
            QTreeWidgetItem* twSubItem = new QTreeWidgetItem(twItem, QStringList(*sub_iter));
            ui->treeWidget->addTopLevelItem(twSubItem);
        }
    }

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
