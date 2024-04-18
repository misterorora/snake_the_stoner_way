#ifndef SCHNECKE_H
#define SCHNECKE_H

#include <raylib.h>
#include <deque>

class Schnecke {
public:
    Texture2D texture;  //raylib Methode zum darstellen bzw. Laden von Textures
    Vector2 position;

    Schnecke(std::deque<Vector2> schlangeBody);     //Konstruktor
       
    ~Schnecke();    //Dekonstruktor

    void Draw();

    Vector2 GenerateRandomCell();   //generiert neue Zelle

    Vector2 GenerateRandomPosition(std::deque<Vector2> schlangeBody);
};

#endif // SCHNECKE_H
