#ifndef QOBJECTS_H
#define QOBJECTS_H
#include <QAction>
#include <QLabel>

class Action : public QAction
{
public:
    explicit Action(const QString &text, QObject *parent = nullptr)
        : QAction(text, parent){};

    ~Action(){
        qDebug() << "delete QAction " << text();
    };
};

class Label : public QLabel
{
public:
    explicit Label(const QString &text, QWidget *parent=nullptr, Qt::WindowFlags f=Qt::WindowFlags())
        : QLabel(text, parent, f){};

    ~Label(){
        qDebug() << "delete QLabel " << text();
    };
};


#endif // QOBJECTS_H
