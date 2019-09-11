#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>
#include <QPushButton>

// Declare & Make m_button pointer *
QPushButton *m_button;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_button = new QPushButton("Not Clicked", this);
    m_button->setGeometry(QRect(QPoint(100, 100),
    QSize(200, 50)));
    // Add Listener
    connect(m_button, SIGNAL (released()), this, SLOT (buttonHandler()));
}

// Listener
void MainWindow::buttonHandler()
{
    m_button->setText("Cicked");
}

MainWindow::~MainWindow()
{
    delete ui;
}

