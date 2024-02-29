#ifndef PROIECT2_MENIU_H
#define PROIECT2_MENIU_H

#include "Figura.h"

#include <vector>
#include <iostream>
#include <string>
#include <stddef.h>

class Meniu: public Figura {
    static const std::string ADD;
    static const std::string REMOVE;
    static const std::string STOP;
    static const std::string PUNCT;
    static const std::string PATRAT;
    static const std::string DREPTUNGHI;
    static const std::string ROMB;
    static const std::string PARALELOGRAM;
    static const std::string TRAPEZ;

    void DisplayMenuMessage();
public:
    void RunMenu();
    template<typename T>
    void citesteFigura();
    static std::vector<std::string> GetAllCommands();
};

#endif // PROIECT2_MENIU_H