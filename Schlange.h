#ifndef SCHLANGE_H
#define SCHLANGE_H

#include <deque>
#include <raylib.h>

class Schlange {
public:
    std::deque<Vector2> body;
    Vector2 direction;
    bool addSegment;

    Schlange(); // Konstruktor der Klasse Schlange

    void Draw();    // Konstruktor der Klasse Schlange

    void Update();  // Methode zum Aktualisieren der Schlange

    void Reset();   // Reset des Games
};

#endif // SCHLANGE_H
