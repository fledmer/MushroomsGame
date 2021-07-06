#include "maincharacter.h"
#include "widget.h"

void MainCharacter::changeMind(int value)
{
    mind += value;
}

void MainCharacter::changeHealth(int value)
{
    health += value;
}

void MainCharacter::changeMoney(int value)
{
    money += value;
}

MainCharacter::MainCharacter()
{
    //this->mainWidget = mainWidget;

    normal_state = ":/player/image/Persone/NormalState.png";
    current_face = normal_state;

    mind = 100;
    health = 100;
    money = 0;
    stalkingLVL = 0;
}
