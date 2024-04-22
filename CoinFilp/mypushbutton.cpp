#include "mypushbutton.h"
#include <QPainter>.
#include <QPropertyAnimation>
MyPushButton::MyPushButton(QString normalImg,QString pressedImg,QWidget *parent)
    : QPushButton(parent)
    , mNormalImg(normalImg)
    ,mPressedImg(pressedImg)
{
    mStat =Normal;
}

void MyPushButton::moveDown()
{
    QPropertyAnimation *animation  = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    animation->setDuration(100);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::moveUp()
{
    QPropertyAnimation *animation  = new QPropertyAnimation(this,"geometry",this);
    animation->setStartValue(this->geometry());
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setDuration(100);
    animation->start(QAbstractAnimation::DeleteWhenStopped);
}

void MyPushButton::paintEvent(QPaintEvent *ev)
{
    QPainter painter(this);
    QPixmap pix;
    if(mStat == Normal)
    pix.load(mNormalImg);
    if(mStat == Pressed)
    pix.load(mPressedImg);
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    painter.drawText(0,0,this->width(),this->height(),
                     Qt::AlignHCenter|Qt::AlignVCenter,this->text());
}
void MyPushButton::mousePressEvent(QMouseEvent *e){
    this->mStat = Pressed;
    update();
    QPushButton::mousePressEvent(e);
}
void MyPushButton::mouseReleaseEvent(QMouseEvent *e){
    this->mStat = Normal;
    update();
    QPushButton::mouseReleaseEvent(e);
}
