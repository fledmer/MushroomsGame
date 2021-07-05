#include "world.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

World::World()
{
    mainCharacter = new MainCharacter();
    dialogs = new QList<QStringList>();
    messages = new QList<QStringList>();
    firstLvlDialog = new QStringList();
    secondLvlDialog = new QStringList();
    thirdLvlDialog = new QStringList();
    firstLvlMessage = new QStringList();
    secondLvlMessage = new QStringList();
    thirdLvlMessage = new QStringList();
    ReadDialogsFromFile();
    ReadMessageFromFile();
}

void World::ReadDialogsFromFile()
{
    QFile firstFile("dialogs\\firstLVLDialogs.txt");
    QFile secondFile("dialogs\\secondLVLDialogs.txt");
    QFile thirdFile("dialogs\\thirdLVLDialogs.txt");

    firstFile.open(QIODevice::ReadOnly);
    secondFile.open(QIODevice::ReadOnly);
    thirdFile.open(QIODevice::ReadOnly);

    QTextStream stream1(&firstFile);
    while(!stream1.atEnd())
        *firstLvlDialog << stream1.readLine();

    QTextStream stream2(&secondFile);
    while(!stream2.atEnd())
        *secondLvlDialog << stream2.readLine();

    QTextStream stream3(&thirdFile);
    while(!stream3.atEnd())
        *thirdLvlDialog << stream3.readLine();

    firstFile.close();
    secondFile.close();
    thirdFile.close();

    *dialogs << *firstLvlDialog << *secondLvlDialog << *thirdLvlDialog;
}

void World::ReadMessageFromFile()
{
    QFile firstFile("messages\\firstLVLMessage.txt");
    QFile secondFile("messages\\secondLVLMessage.txt");
    QFile thirdFile("messages\\thirdLVLMessage.txt");

    firstFile.open(QIODevice::ReadOnly);
    secondFile.open(QIODevice::ReadOnly);
    thirdFile.open(QIODevice::ReadOnly);

    QTextStream stream1(&firstFile);
    while(!stream1.atEnd()){
        QString str;
        do{
            str = stream1.readLine();
            *firstLvlMessage << str << "\n";
        }while(str != "");
    }

    QTextStream stream2(&firstFile);
    while(!stream2.atEnd()){
        QString str;
        do{
            str = stream2.readLine();
            *secondLvlMessage << str << "\n";
        }while(str != "");
    }

    QTextStream stream3(&firstFile);
    while(!stream3.atEnd()){
        QString str;
        do{
            str = stream3.readLine();
            *thirdLvlMessage << str << "\n";
        }while(str != "");
    }

    firstFile.close();
    secondFile.close();
    thirdFile.close();

    *messages << *firstLvlMessage << *secondLvlMessage << *thirdLvlMessage;
}
