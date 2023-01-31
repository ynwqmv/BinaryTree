#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "tree.h"
#include <QMainWindow>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void add();
    void json();



private:
    Ui::MainWindow *ui;
    createTree* mBinTree;
};




#endif // MAINWINDOW_H
