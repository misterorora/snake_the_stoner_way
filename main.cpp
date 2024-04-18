#include "main.h"
#include <iostream>
#include "Schnecke.h"
#include "Schlange.h"
#include "Spiel.h"

using namespace std;

// Definition der Farben
Color beige = { 226,203,176,255 };
Color blue = { 152,174,182,255 };
// Zellengrid
int cellSize = 30;
int cellCount = 25;
int offsetGrid = 75;

// Variable zum Check nach letztem Update
double lastUpdated = 0;

// Verzögerungsmethode
bool eventTriggered(double interval) {
    double currentTime = GetTime();
    if (currentTime - lastUpdated >= interval) {
        lastUpdated = currentTime;
        return true;
    }
    else return false;
}

bool ElementInDeque(Vector2 element, deque<Vector2> deque) {
    for (unsigned int i = 0; i < deque.size(); i++) {
        if (Vector2Equals(deque[i], element)) {
            return true;
        }
    }
    return false;
}

int main() {
    cout << "Starte Snake..." << endl;

    // Breite und Höhe des spielbaren Fensters 
    InitWindow(2 * offsetGrid + cellSize * cellCount, 2 * offsetGrid + cellSize * cellCount, "Snake the Stoner way ");

    SetTargetFPS(90);  // Framerate 90 Frames per Second

    Spiel spiel = Spiel();

    // Game Loop
    while (WindowShouldClose() == false) {
        BeginDrawing();

        if (eventTriggered(0.2)) {
            spiel.Update();
        }

        // Positionsänderungen der Schlange
        if (IsKeyPressed(KEY_UP) && spiel.schlange.direction.y != 1) {
            spiel.schlange.direction = { 0, -1 };
            spiel.running = true;
        }
        if (IsKeyPressed(KEY_DOWN) && spiel.schlange.direction.y != -1) {
            spiel.schlange.direction = { 0, 1 };
            spiel.running = true;
        }
        if (IsKeyPressed(KEY_LEFT) && spiel.schlange.direction.x != 1) {
            spiel.schlange.direction = { -1, 0 };
            spiel.running = true;
        }
        if (IsKeyPressed(KEY_RIGHT) && spiel.schlange.direction.x != -1) {
            spiel.schlange.direction = { 1, 0 };
            spiel.running = true;
        }
        // Aufräumen und Darstellen des Rahmens und des Hintergrundes
        DrawRectangleLinesEx({ (float)offsetGrid - 5,(float)offsetGrid - 5,(float)cellSize * cellCount + 10,(float)cellSize * cellCount + 10 }, 5, blue);
        ClearBackground(beige);
        // Zeichnen Spielfeld inklusive Schnegge und Schlange, Überschrift und Score
        spiel.Draw();
        DrawText("Snake the Stoner way", offsetGrid - 5, 20, 40, blue); // Display Überschrift
        DrawText(TextFormat("%i", spiel.score), offsetGrid - 5, offsetGrid + cellSize * cellCount + 10, 40, blue); // Display score on the bottom of the screen
        EndDrawing();

    }
    CloseWindow();
    return 0;
}
