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
    MainCharacter *mainCharacter;
    World();

    void ReadDialogsFromFile();

};

#endif // WORLD_H
