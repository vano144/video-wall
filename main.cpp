#include <QApplication>
#include "single_application.h"
#include <QDebug>
//Qsettings
int main(int argc, char *argv[])
{
    Single_application a(argc, argv,"myUniqueKey");

    if(a.isalreadyExists()){
        for (int i = 1;i<argc;i++)
        {
            a.sendMessage(argv[i]);
        }
        return 0;
    }
    else qDebug() << "I am first";
    return a.exec();
}
