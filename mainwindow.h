#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "qobjects.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_action_DelToolBar_triggered();
    void on_action_DelStatusBar_triggered();
    void on_action_DelMenuBar_triggered();
    void on_action_Exit_triggered();

private:
    QToolBar *baseToolBar;
    QMenu *menu_File;
    QStatusBar *statusbar;
    //- - - - - - - - - - - -
    Action *action_DelToolBar;
    Action *action_DelStatusBar;
    Action *action_DelMenuBar;
    Action *action_Exit;
    //- - - - - - - - - - - -
    Label *test;
};  // class MainWindow
#endif // MAINWINDOW_H
