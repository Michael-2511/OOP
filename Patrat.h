#ifndef PROIECT2_PATRAT_H
#define PROIECT2_PATRAT_H

#include "Punct.h"

class Patrat: public Punct { // pune : public Punct daca crapa
protected:
    Punct stanga_jos;
    float latura;
    int valid;
public:
    Patrat();
    Patrat(Punct stanga_jos, float latura);
    Patrat(const Patrat& patrat);
    virtual ~Patrat();
    // operator=
    Patrat& operator=(const Patrat& patrat) {
        stanga_jos = patrat.stanga_jos;
        latura = patrat.latura;
        valid = patrat.valid;
        return *this;
    }
    // operator>>
    friend std::istream& operator>>(std::istream& in, Patrat& patrat);
    // operator<<
    friend std::ostream& operator<<(std::ostream& out, Patrat& patrat);
    
    void Afisare(std::ostream& out);
    void Afisare();

    int getValid();

    float Perimetru();
    float Arie();
};

#endif // PROIECT2_PATRAT_H