#include "Schlange.h"
#include "main.h"

Schlange::Schlange() {
    body = { Vector2{6,9},Vector2{5,9},Vector2{4,9} };  // Initialisiere den K�rper der Schlange mit drei Segmenten
    direction = { 1, 0 };   // Setze die Richtung der Schlange auf rechts (1,0)
    addSegment = false;
}

void Schlange::Draw() {
    for (unsigned i = 0; i < body.size(); i++) {    // Iteriere �ber alle Segmente im K�rper der Schlange
        float x = body[i].x;
        float  y = body[i].y;
        Rectangle segment = { offsetGrid + x * cellSize, offsetGrid + y * cellSize, (float)cellSize, (float)cellSize }; // Erstelle ein Rechteck f�r das aktuelle Segment
        DrawRectangleRounded(segment, 0.5, 6, blue);    // Zeichne das aktuelle Segment als abgerundetes Rechteck in blauer Farbe
    }
}

void Schlange::Update() {   // Methode zum Aktualisieren der Schlange
    body.push_front(Vector2Add(body[0], direction));
    if (addSegment == true) {
        addSegment = false;
    }
    else {
        body.pop_back();
    }
}

void Schlange::Reset() {     // Methode zum Zur�cksetzen der Schlange auf ihren Ausgangszustand
    body = { Vector2{6,9}, Vector2{5,9}, Vector2{4,9} };
    direction = { 1, 0 };
}
