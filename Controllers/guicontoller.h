#ifndef GUICONTOLLER_H
#define GUICONTOLLER_H
#include <QObject>


class GUIContoller: public QObject
{
    Q_OBJECT

public:
    GUIContoller();


signals :
    void click();
public slots :
    void onclicked();

};

#endif // GUICONTOLLER_H
