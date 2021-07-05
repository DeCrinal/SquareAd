#include "squaredhero.h"
#include <QObject>
#include <QCoreApplication>
#include"SquaredScene.h"
#include<QMessageBox>
SquaredHero::SquaredHero(QObject*parent): QObject(parent), QGraphicsItem()
{
    vector = "right";
    velocity = 1;
    deltaX = 0;
    deltaY = 0;
    gameTimer = new QTimer(this);
    //scenePtr = nullptr;
    gameTimer->setSingleShot(false);
    connect(gameTimer,&QTimer::timeout,this,&SquaredHero::GameTimer);
    gameTimer->start(100);

}
SquaredHero::~SquaredHero(){
    delete gameTimer;
}
QRectF SquaredHero::boundingRect() const
{
    return QRectF(-10,-10,20,20);
}

void SquaredHero::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QColor(240,41,26));
    painter->drawRect(-10,-10,20,20);
}
void SquaredHero:: GameTimer(){
    if(GetAsyncKeyState('A')){
            vector = "left";
        }
        if(GetAsyncKeyState('D')){
            vector = "right";
        }
        if(GetAsyncKeyState('W')){
            vector = "top";
        }
        if(GetAsyncKeyState('S')){
            vector = "bot";
        }
        if(vector=="left"){
            this->setX(this->x() - velocity);
            deltaX-=velocity;
            if(scene()->collidingItems(this).isEmpty()==false){
                this->setY(this->y()-deltaY);
                this->setX(this->x()-deltaX);
                deltaX=0;
                deltaY=0;
                vector = "right";
            }
        }
        if(vector=="right"){
            this->setX(this->x() + velocity);
            deltaX+=velocity;
            if(scene()->collidingItems(this).isEmpty()==false){
                this->setY(this->y()-deltaY);
                this->setX(this->x()-deltaX);
                deltaX=0;
                deltaY=0;
                vector = "right";
            }
        }
        if(vector == "top"){
            this->setY(this->y() - velocity);
            deltaY-=velocity;
            if(scene()->collidingItems(this).isEmpty()==false){
                this->setY(this->y()-deltaY);
                this->setX(this->x()-deltaX);
                deltaX=0;
                deltaY=0;
                vector = "right";
            }
        }
        if(vector=="bot"){
            this->setY(this->y() + velocity);
            deltaY +=velocity;
            if(scene()->collidingItems(this).isEmpty()==false){
                this->setY(this->y()-deltaY);
                this->setX(this->x()-deltaX);
                deltaX=0;
                deltaY=0;
                vector = "right";
            }
        }
        if(deltaY>=450&&deltaX>=600){
           velocity = 0;
           QMessageBox::information(0,"Message","You win!");
           deltaY=0;
        }

}
