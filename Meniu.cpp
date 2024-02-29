#include "Meniu.h"
#include <typeinfo>

const std::string Meniu::ADD = "ADD";
const std::string Meniu::REMOVE = "REMOVE";
const std::string Meniu::STOP = "STOP";
const std::string Meniu::PUNCT = "PUNCT";
const std::string Meniu::PATRAT = "PATRAT";
const std::string Meniu::DREPTUNGHI = "DREPTUNGHI";
const std::string Meniu::ROMB = "ROMB";
const std::string Meniu::PARALELOGRAM = "PARALELOGRAM";
const std::string Meniu::TRAPEZ = "TRAPEZ";

// Meniu interactiv
void Meniu::RunMenu() {
    DisplayMenuMessage();

    std::string command;
    std::cin >> command;

    while (command != STOP) {
        if (command == ADD) {

            std::cout << "Ce figura doresti sa adaugi? " << std::endl;
            std::string figura;
            std::cin >> figura;

            if (figura == PUNCT) {
                citesteFigura<Punct>();
            }
            else if (figura == PATRAT) {
                citesteFigura<Patrat>();
            }
            else if (figura == DREPTUNGHI) {
                citesteFigura<Dreptunghi>();
            }
            else if (figura == ROMB) {
                citesteFigura<Romb>();
            }
            else if (figura == PARALELOGRAM) {
                citesteFigura<Paralelogram>();
            }
            else if (figura == TRAPEZ) {
                citesteFigura<Trapez>();
            }
            else {
                std::cout << "Comanda invalida." << std::endl;
            }
            std::cout << std::endl;
            DisplayMenuMessage();
        }
        else if (command == REMOVE) {
            int pozitie;
            std::cin >> pozitie;
            StergeFigura(pozitie);
            std::cout << std::endl;
            DisplayMenuMessage();
        }
        else {
            std::cout << "Comanda invalida" << std::endl;
            DisplayMenuMessage();
        }
        std::cin >> command;
    }
    AfisareFiguri();
}

std::vector<std::string> Meniu::GetAllCommands() {
    std::vector<std::string> commands;
    commands.push_back(ADD);
    commands.push_back(REMOVE);
    commands.push_back(STOP);
    commands.push_back(PUNCT);
    commands.push_back(PATRAT);
    commands.push_back(DREPTUNGHI);
    commands.push_back(ROMB);
    commands.push_back(PARALELOGRAM);
    commands.push_back(TRAPEZ);
    return commands;
}

template<typename T>
void Meniu::citesteFigura() {
    T* figura = new T;
    std::cin >> (*figura);
    std::cout << (*figura) << std::endl;
    if ((*figura).getValid()) {
        std::cout << (*figura).Perimetru() << std::endl;
        std::cout << (*figura).Arie() << std::endl;
    }
    AdaugaFigura(figura);
    std::cout << "citesteFigura() - functie template" << std::endl;
}

void Meniu::DisplayMenuMessage() {
    std::cout << ADD << " PUNCT|PATRAT|DREPTUNGHI|ROMB|PARALELOGRAM|TRAPEZ - citeste si adauga o noua figura." << std::endl
              << REMOVE << " x - sterge figura de pe pozitia x." << std::endl
              << STOP << " - opreste programul." << std::endl
              << std::endl;
}