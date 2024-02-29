#include "Figura.h"
#include <stddef.h>

Figura::Figura() {}
Figura::Figura(const Figura& figura) {
    std::cout << " este aici in figura" << std::endl;
    //TODO trebuie copiata fiecare forma
}
Figura::~Figura() {
    for(int i = 0; i < figuri.size(); i++) {
        delete figuri[i];
    }
}

void Figura::AfisareFiguri() {
    for (int i = 0; i < figuri.size(); i++) {
        std::cout << *figuri[i] << std::endl;
    }
}

void Figura::AdaugaFigura(Punct* figura) {
    figuri.push_back(figura);
}

void Figura::StergeFigura(int pozitie) {
    try {
        if (pozitie < 0 || pozitie > this-> figuri.size())
            throw pozitie;
        delete figuri[pozitie];
        figuri.erase(figuri.begin() + pozitie);
        std::cout << "Figura de pe pozitia " << pozitie << " a fost stearsa." << std::endl;
    }
    catch (int pozitie) {
        std::cout << "Pozitie invalida." << std::endl;
    }
}
