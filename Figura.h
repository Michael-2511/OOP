#ifndef PROIECT2_FIGURA_H
#define PROIECT2_FIGURA_H

#include "Punct.h"
#include <vector>

class Figura {
protected:
    std::vector<Punct*> figuri;
public:
    Figura();
    Figura (const Figura& figura);
    virtual ~Figura();

    void AfisareFiguri();
    void AdaugaFigura(Punct*);
    void StergeFigura(int pozitie);
};

#endif // PROIECT2_FIGURA_H