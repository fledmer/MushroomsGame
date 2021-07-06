#ifndef MAINCHARACTER_H
#define MAINCHARACTER_H
#include <QString>

class MainCharacter
{
public:
    QString normal_state;
    QString current_face;

    int mind;
    int health;
    int money;

    int stalkingLVL;


    void changeMind(int value);
    void changeHealth(int value);
    void changeMoney(int value);

    MainCharacter();
};

#endif // MAINCHARACTER_H
