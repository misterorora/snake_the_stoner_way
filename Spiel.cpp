#include "Spiel.h"
#include "main.h"

Spiel::Spiel() : schlange(), schnecke(schlange.body), running(true), score(0) { //setzt Spiel, schlange und schnecke, running zu true um ggf. Spiel bei Ende zu pausieren
}    

void Spiel::Draw() {    
    schlange.Draw();
    schnecke.Draw();
}

void Spiel::Update() {  //updated Spiel, falls kein Fehler checken nach Kollisionen und Update Position Schlange
    if (running) {
        schlange.Update();
        checkKollisionSchnecke();
        checkKollisionMitRand();
        checkKollisionMitSchwanz();
    }
}

void Spiel::checkKollisionSchnecke() {              //aufsammeln der Schnegge
    if (Vector2Equals(schlange.body[0], schnecke.position)) {
        schnecke.position = schnecke.GenerateRandomPosition(schlange.body);
        schlange.addSegment = true;
        score++;
    }
}

void Spiel::checkKollisionMitRand() {       //checken der Wandkollision
    if (schlange.body[0].x == cellCount || schlange.body[0].x == -1) {
        GameOver();
    }
    if (schlange.body[0].y == cellCount || schlange.body[0].y == -1) {
        GameOver();
    }
}

void Spiel::checkKollisionMitSchwanz() {
    std::deque<Vector2> headlessBody = schlange.body;
    headlessBody.pop_front();
    if (ElementInDeque(schlange.body[0], headlessBody)) {
        GameOver();
    }
}

void Spiel::GameOver() {    //resetet Spiel, setzt Position auf alte Startposition, pausiert bis zur nächsten Eingabe 
    schlange.Reset();
    schnecke.position = schnecke.GenerateRandomPosition(schlange.body);
    running = false;
    score = 0;
}
