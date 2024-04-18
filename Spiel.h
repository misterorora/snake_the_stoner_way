#ifndef SPIEL_H
#define SPIEL_H

#include "Schlange.h"
#include "Schnecke.h"

class Spiel {
public:
    Schlange schlange;
    Schnecke schnecke;
    bool running;
    int score;      //score fürs Zählen der eingesammelten Schneggen

    Spiel();

    void Draw();

    void Update();

    void checkKollisionSchnecke();  //selbsterklärend :D 

    void checkKollisionMitRand();

    void checkKollisionMitSchwanz();

    void GameOver();    
};

#endif // SPIEL_H
