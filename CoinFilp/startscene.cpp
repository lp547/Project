#include "startscene.h"
#include<QPushButton>
#include"mypushbutton.h"
#include <QTimer>

StartScene::StartScene(QWidget *parent) : MyMainWindow(parent)
{
    this->setWindowTitle("开始场景");
    MyPushButton *btnStart = new MyPushButton(":/res/MenuSceneStartButton.png",":/res/MenuSceneStartButton.png",this);
    btnStart->resize(114,114);
    btnStart->move((this->width()-btnStart->width())/2,
                   this->height()*3/4-btnStart->height()/2);

    connect(&this->mySelectScene,&SelectScene::backBtnClicked,[=](){
        this->show();
        this->mySelectScene.hide();
    });

    connect(btnStart,&MyPushButton::clicked,[=](){
        btnStart->setEnabled(false);
        btnStart->moveDown();
        QTimer::singleShot(150,[=](){
        btnStart->moveUp();
        });
        QTimer::singleShot(300,[=](){
        btnStart->setEnabled(true);

        this->hide();
        this->mySelectScene.show();
        });
    });
}
