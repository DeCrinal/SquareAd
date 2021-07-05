#pragma once
#include <QGraphicsScene>
#include "squaredhero.h"
#include <QTimer>
class SqScene:public QGraphicsScene{
    Q_OBJECT
private:
    SquaredHero*squaredHero;
    void createBoards();
public:
    SqScene(QObject*parent = nullptr);
};
