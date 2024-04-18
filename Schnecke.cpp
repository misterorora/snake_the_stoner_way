#include "Schnecke.h"
#include <iostream>
#include "main.h"

Schnecke::Schnecke(std::deque<Vector2> schlangeBody) {      //Schneggen Konstruktor, importiert IMG aus "Graphics" Ordner
    Image image = LoadImage("Graphics/schnecke.png");
    texture = LoadTextureFromImage(image);
    UnloadImage(image);
    position = GenerateRandomPosition(schlangeBody);
}

Schnecke::~Schnecke() {     //Dekonstruktor
    UnloadTexture(texture);
}

void Schnecke::Draw() {
    DrawTexture(texture, offsetGrid + position.x * cellSize, offsetGrid + position.y * cellSize, WHITE);
}

Vector2 Schnecke::GenerateRandomCell() {        //Generiert zufällige Zelle für Spawn der Schnecken
    float x = GetRandomValue(0, cellCount - 1);
    float y = GetRandomValue(0, cellCount - 1);
    return Vector2{ x,y };
}

Vector2 Schnecke::GenerateRandomPosition(std::deque<Vector2> schlangeBody) {        // Methode zum Generieren einer zufälligen Position für die Schnecke unter Berücksichtigung ihres Körpers
    Vector2 position = GenerateRandomCell();
    while (ElementInDeque(position, schlangeBody)) {
        position = GenerateRandomCell();
    }
    return position;
}
