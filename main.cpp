#include <iostream>

#include "Punct.cpp"
#include "Patrat.cpp"
#include "Dreptunghi.cpp"
#include "Romb.cpp"
#include "Paralelogram.cpp"
#include "Trapez.cpp"
#include "Figura.cpp"
#include "Meniu.cpp"

int main() {
    Meniu menu;
    Meniu::GetAllCommands();
    menu.RunMenu();
}