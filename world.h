#ifndef WORLD_H
#define WORLD_H
#include <maincharacter.h>
#include <QStringList>

class World
{
public:
    QList<QStringList> *dialogs;
    QStringList *firstLvlDialog;
    QStringList *secondLvlDialog;
    QStringList *thirdLvlDialog;
    QList<QStringList> *messages;
    QStringList *firstLvlMessage;
    QStringList *secondLvlMessage;
    QStringList *thirdLvlMessage;
    MainCharacter *mainCharacter;
    World();

    void ReadDialogsFromFile();
    void ReadMessageFromFile();

};

#endif // WORLD_H
