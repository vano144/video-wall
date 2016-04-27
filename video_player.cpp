#include "video_player.h"
#include <QDebug>
#include <QLayout>
#include <QBoxLayout>
#include <QSizePolicy>

video_player::video_player(QWidget *parent) : QWidget(parent)
{
    QGridLayout *mainLayout = new QGridLayout(this);
//    QLayout *mainLayout = new QLayout(this);
    //QBoxLayout *mainLayout = new QBoxLayout(QBoxLayout::LeftToRight,this);
    i=0;
    j=0;
    h=0;
    w=0;
    this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setGeometry(0,0,2048,1024);
    //this->setLayout(mainLayout);
}
void video_player::resize()
{
    QVector<QWidget*> *widgets= new QVector<QWidget*>();
    int capacity=this->layout()->count();

    for (int i=0;i<capacity;i++)
    {
        widgets->push_back(dynamic_cast<QWidget*>(this->layout()->itemAt(i)));
    }
    for (int i=0;i<capacity;i++)
    {

    }
}

void video_player::addVideo(QString path)
{

    QMediaPlayer* player = new QMediaPlayer();
    player->setMedia(QUrl::fromLocalFile(path));
    QVideoWidget* a = new QVideoWidget();
    player->setVideoOutput(a);
    a->setGeometry(0,0,2000,2000);
  a->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
//    if (j%2==0 && j!=0)
//    {
//        if (w+1-h>1)
//        {
//            w++;
//            j++;
//            i=0;
//        } else {
//        h++;
//        i++;
//        j=0;
//        }
//    }
    //j++;

//    if (j!=0 && j%2!=0)
//    {
//        QLayoutItem* item=layout()->takeAt()
//        QVideoWidget* widg=dynamic_cast<QVideoWidget*>(item);
//        dynamic_cast<QGridLayout*>(layout())->addWidget(widg,j-1,i,2,2);
//        dynamic_cast<QGridLayout*>(layout())->addWidget(a,j,i,1,1);
//        show();
//        player->play();
//        return;
//    }
        //dynamic_cast<QBoxLayout*>(layout())->addWidget(a,1);
        //resize();
    //adjustSize();
    dynamic_cast<QGridLayout*>(layout())->addWidget(a,j,i,1,1);
    a->sizeHint();
    if (i+1>w && j+1>h)
    {
        if (w+1-h>1)
        {
            j=h+1;
            i=0;
        }
        else
        {
            i++;
            j=0;
        }
    }
    else
    {
        if (i==w)
        {
            j++;
        }
        else
        {
            i++;
        }
    }
    if (i>w) w=i;
    if (j>h) h=j;
    qDebug()<<"i: "<<i;
    qDebug()<<"j: "<<j<<endl;

    show();
    //TODO: in circle max j, then max i
    player->play();
//    a->resize( 500, 500 );
//             a->adjustSize();
//             a->resize( 2000, 2000 );
    //a->adjustSize();
    //a->resize(1000,5800);
    //a->updateGeometry();
    //a->adjustSize();

}
