#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QProgressDialog>
#include "tree.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow){

    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::add);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::json);
    connect(ui->actionExit, &QAction::triggered, this,[](){ QApplication::exit(); });
    mBinTree = new createTree();

}

MainWindow::~MainWindow()
{
    delete ui;
    delete mBinTree;
}

void MainWindow::add()
{

    if(ui->lineEdit->text().isEmpty())
    {
        QMessageBox::information(this,tr("Message"), tr("Please, do not left the empty fields.\n\nOtherwise, you will get `null` in json output"));
        return;
    }
    int data = ui->lineEdit->text().toInt();
    mBinTree->insert(data);
    QMessageBox::information(this,"Tree", "Data was added in tree successfully");
    mBinTree->print();

}

void MainWindow::json()
{

    QProgressDialog progress("Exporting data to .json file...", "Cancel", 0, 100, this);
    progress.setWindowModality(Qt::WindowModal);
    progress.show();

    for (int i = 0; i <= 100; i++)
    {
        progress.setValue(i);
        qApp->processEvents();
        if (progress.wasCanceled())
        {
            break;
        }
    }

    mBinTree->addJson();
    progress.setValue(100);
    QMessageBox::information(this,"Export", "Data was successfully exported in .json file!");
}


