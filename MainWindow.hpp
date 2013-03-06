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
    Ui::MainWindow *ui;
    QMap<QString, QString> m_Info;
    QMap<QString, Repository> m_Repositories;
};

#endif // MAINWINDOW_HPP
