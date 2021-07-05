#pragma once
#include <QMainWindow>
#include <QWidget>
#include <QGraphicsScene>
#include<QGraphicsItem>
#include "SquaredScene.h"
#include "ui_mainwindow.h"
class SqScene;
class MainForm : public QMainWindow, public Ui::MainWindow
{
    Q_OBJECT

public:
    MainForm(QWidget *parent = nullptr);
    ~MainForm();
private:
    SqScene *scene;
};
