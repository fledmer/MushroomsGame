#include "world.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

World::World()
{
    mainCharacter = new MainCharacter();
    dialogs = new QList<QStringList>();
    firstLvlDialog = new QStringList();
    secondLvlDialog = new QStringList();
    thirdLvlDialog = new QStringList();
        ReadDialogsFromFile();
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

