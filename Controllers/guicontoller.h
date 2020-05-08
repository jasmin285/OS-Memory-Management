#ifndef GUICONTOLLER_H
#define GUICONTOLLER_H

#include <QWidget>
#include <QObject>
#include <QPushButton>
#include "../GUI/mainwindow.h"
#include "../GUI/holeswidget.h"
#include "../GUI/processwidget.h"
class GUIContoller : public QObject
{
    Q_OBJECT
public:
    GUIContoller();
private:
    static MainWindow* main;
    static HolesWidget* w1;
private slots:
    void onNxtClicked();

};

#endif // GUICONTOLLER_H