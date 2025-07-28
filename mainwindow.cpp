#include "mainwindow.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QStatusBar>

//================================================================================
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    qDebug() << "Start";

    setWindowTitle(tr("Тестирование освобождения QObjects. v002"));
    resize(480, 320);

    statusBar()->showMessage("");   // активация встроенного statusBar

    Action *currentAct;    // для упрощения копипаста
    //--------------------------------------------------------------------------------
    QString delToolBarTip = tr("Удалить ToolBar");
    action_DelToolBar = currentAct = new Action(delToolBarTip, this);
    currentAct->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::WindowClose));
    currentAct->setToolTip(delToolBarTip);
    currentAct->setStatusTip(delToolBarTip);
    connect(currentAct, &Action::triggered, this, &MainWindow::on_action_DelToolBar_triggered);

    QString delStatusBarTip = tr("Удалить StatusBar");
    action_DelStatusBar = currentAct = new Action(delStatusBarTip); // "пасынок"
    currentAct->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::WindowClose));
    currentAct->setToolTip(delStatusBarTip);
    currentAct->setStatusTip(delStatusBarTip);
    connect(currentAct, &Action::triggered, this, &MainWindow::on_action_DelStatusBar_triggered);


    QString DelMenuBarTip = tr("Удалить меню");
    action_DelMenuBar = currentAct = new Action(DelMenuBarTip); // "пасынок"
    currentAct->setIcon(QIcon::fromTheme(QIcon::ThemeIcon::WindowClose));
    currentAct->setToolTip(DelMenuBarTip);
    currentAct->setStatusTip(DelMenuBarTip);
    connect(currentAct, &Action::triggered, this, &MainWindow::on_action_DelMenuBar_triggered);

    action_Exit = currentAct = new Action(tr("Выход"), this);
    QString exitTip = tr("Завершить программу");
    currentAct->setToolTip(exitTip);
    currentAct->setStatusTip(exitTip);
    connect(currentAct, &Action::triggered, this, &MainWindow::on_action_Exit_triggered);

    menu_File = menuBar()->addMenu(tr("Tool"));
    menu_File->addAction(action_DelToolBar);
    menu_File->addAction(action_DelStatusBar);
    menu_File->addAction(action_DelMenuBar);
    menu_File->addSeparator();
    menu_File->addAction(action_Exit);

    baseToolBar = QMainWindow::addToolBar(tr("Основная"));
    baseToolBar->addAction(action_DelToolBar);
    baseToolBar->addAction(action_DelStatusBar);
    baseToolBar->addAction(action_DelMenuBar);
    baseToolBar->addSeparator();

    test = new Label(tr("Тест"), this);
    baseToolBar->addWidget(test);

    // statusBar()->addPermanentWidget(test);
    qDebug() << "Родитель Label 'Тест' - " << test->parentWidget();
};

//================================================================================
MainWindow::~MainWindow() {
    qDebug() << "Finish";
}

void MainWindow::on_action_DelToolBar_triggered(){
    baseToolBar->deleteLater();
    action_DelToolBar->setEnabled(false);
};

void MainWindow::on_action_DelStatusBar_triggered(){
    statusBar()->deleteLater();
    action_DelStatusBar->setEnabled(false);
};

void MainWindow::on_action_DelMenuBar_triggered(){
    menuBar()->deleteLater();
    action_DelMenuBar->setEnabled(false);
};


void MainWindow::on_action_Exit_triggered(){
    QApplication::quit();
};





