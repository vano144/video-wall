#include "single_application.h"
#include <QTimer>
#include <iostream>
#include <QDebug>
#include <QString>
#include <QVideoWidget>
Single_application::Single_application(int &argc, char *argv[], const QString uniqueKey): QApplication(argc, argv)
{
    {
//        player = new QMediaPlayer();
//        QDialog* lol =new QDialog;
//        QGridLayout* lal = new QGridLayout;
//        //    playlist = new QMediaPlaylist(player);
        ply = new video_player();
        sharedMemory.setKey(uniqueKey);

        // when  can create it only if it doesn't exist
        if (sharedMemory.create(5000))
        {
            sharedMemory.lock();
            *(char*)sharedMemory.data() = '\0';
            sharedMemory.unlock();

            alreadyExists = false;

            // start checking for messages of other instances.
            QTimer *timer = new QTimer(this);
            connect(timer, SIGNAL(timeout()), this, SLOT(checkForMessage()));
            timer->start(200);
        }
        // it exits, so we can attach it?!
        else if (sharedMemory.attach()){
            alreadyExists = true;
        }
        else{
            // error
        }

    }
}

void Single_application::checkForMessage()
{
    QString arguments;
    QStringList  list;
    sharedMemory.lock();
    char *from = (char*)sharedMemory.data();

    while(*from != '\0'){
        int sizeToRead = int(*from);
        qDebug()<<int(*from);
        qDebug()<<"ds";
        ++from;

        QByteArray byteArray = QByteArray(from, sizeToRead);
        byteArray[sizeToRead] = '\0';
        from += sizeToRead;

        arguments = QString::fromUtf8(byteArray.constData());
         if (arguments=="open")
         {
             status=1;
         }
         if (arguments=="close")
         {

             status=2;
             sharedMemory.unlock();
             this->closeAllWindows();
         }
         if (arguments!="open" && arguments!="close")
         {
             if (status==1)
             {
                 qDebug() << "open command is running "+arguments;
                 ply->addVideo(arguments);

             }
             if (status==2)
             {
                 qDebug() << "close command is running "+arguments;
             }
         }
    }

    *(char*)sharedMemory.data() = '\0';
    sharedMemory.unlock();
    arguments="";
//    list<<arguments;
//    if(arguments.size()>0) emit messageAvailable(list);
//    list.clear();
//    player = new QMediaPlayer;

//    playlist = new QMediaPlaylist(player);
//    playlist->addMedia(QUrl("http://example.com/myclip1.mp4"));
//    playlist->addMedia(QUrl("http://example.com/myclip2.mp4"));

//    videoWidget = new QVideoWidget;
//    player->setVideoOutput(videoWidget);

//    videoWidget->show();
//    playlist->setCurrentIndex(1);
//    player->play();
}

bool Single_application::sendMessage(const QString &message)
{
    //we cannot send mess if we are master process!
    if (isMainApp()){
        return false;
    }
    QByteArray byteArray;
    byteArray.append(char(message.size()));
    byteArray.append(message.toUtf8());
    byteArray.append('\0');

    sharedMemory.lock();
    char *to = (char*)sharedMemory.data();
    while(*to != '\0'){
        int sizeToRead = int(*to);
        to += sizeToRead + 1;
    }

    const char *from = byteArray.data();
    memcpy(to, from, qMin(sharedMemory.size(), byteArray.size()));
    sharedMemory.unlock();

    return true;
}

bool Single_application::isalreadyExists()
{
    return alreadyExists;
}
bool Single_application::isMainApp()
{
    return !alreadyExists;
}
