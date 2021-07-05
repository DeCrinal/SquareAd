#pragma once
#include <QGraphicsItem>
#include <QTimer>
#include <QObject>
#include <QWidget>
#include <QPainter>
#include <string>
#include <windows.h>
class SquaredHero: public QObject, public QGraphicsItem
{
public:
    SquaredHero(QObject*parent=nullptr);
    ~SquaredHero();
private slots:
    void GameTimer();
private:
    std::string vector;
    int velocity;
   int deltaX, deltaY;
    QTimer *gameTimer;
    QRectF boundingRect() const;
    void paint(QPainter*painter, const QStyleOptionGraphicsItem *option,
               QWidget*widget);
};
