#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include "Portage.hpp"

#include <QMainWindow>

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
    Portage m_Portage;
};

#endif // MAINWINDOW_HPP
