#include "videoplayer.h"

VideoPlayer::VideoPlayer(QWidget *parent) : QMainWindow(parent)
{
    QGridLayout* lal = new QGridLayout;
    qDebug() << "open command is running "+arguments;
    player->setMedia(QUrl::fromLocalFile(arguments));
    //lal->addWidget(qobject_cast<QWidget*>(player),0,0);
    //lol->setLayout(lal);
    QVideoWidget* a = new QVideoWidget();
    a->setGeometry(100,100,400,500);
    player->setVideoOutput(a);
    //a->show();
    i++;
    player->play();
    lal->addWidget(a,i,0);

    lol->setLayout(lal);
    lol->show();
}
void VideoPlayer::
