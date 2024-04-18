#ifndef MAIN_H
#define MAIN_H

#include <deque>
#include <raylib.h>
#include <raymath.h>

// Definition der Farben
extern Color beige;
extern Color blue;
// Zellengrid
extern int cellSize;
extern int cellCount;
extern int offsetGrid;

// Variable zum Check nach letztem Update
extern double lastUpdated;

// Verzögerungsmethode
bool eventTriggered(double interval);

// Element in Deque überprüfen
bool ElementInDeque(Vector2 element, std::deque<Vector2> deque);

#endif // MAIN_H
