#ifndef SPIEL_H
#define SPIEL_H

#include "Schlange.h"
#include "Schnecke.h"

class Spiel {
public:
    Schlange schlange;
    Schnecke schnecke;
    bool running;
    int score;      //score f�rs Z�hlen der eingesammelten Schneggen

    Spiel();

    void Draw();

    void Update();

    void checkKollisionSchnecke();  //selbsterkl�rend :D 

    void checkKollisionMitRand();

    void checkKollisionMitSchwanz();

    void GameOver();    
};

#endif // SPIEL_H
