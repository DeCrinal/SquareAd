#include "mainwindow.h"
#include "SquaredScene.h"
#include "squaredhero.h"
MainForm::MainForm(QWidget *parent)
    :QMainWindow(parent)
{
    setupUi(this);
    setWindowTitle("SquareAd");
    scene = new SqScene;
    scene->setSceneRect(0,0,1100,600);
    this->graphicsView->setScene(scene);
}

MainForm::~MainForm()
{
    delete scene;
}

