#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Repository.hpp"

#include <QMainWindow>
#include <QMap>
#include <QTreeWidgetItem>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void categoryChanged();

private:
    class callbackCategories
    {
    public:
        callbackCategories(MainWindow& parent, QTreeWidgetItem* item);
        void operator()(const QString& strCategory);

    private:
        MainWindow& m_Parent;
        QTreeWidgetItem* m_Item;
    };

    Ui::MainWindow *ui;
    QMap<QString, QString> m_Info;
    QMap<QString, Repository> m_Repositories;
    Repository gentoo;
};

#endif // MAINWINDOW_HPP
