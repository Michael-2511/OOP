#ifndef PROIECT2_PARALELOGRAM_H
#define PROIECT2_PARALELOGRAM_H

#include "Dreptunghi.h"
#include "Romb.h"

class Paralelogram: public Dreptunghi, public Romb {
protected:
    int valid;
public:
    Paralelogram();
    Paralelogram(Punct stanga_jos, Punct colt_opus, float latura, float latura2);
    Paralelogram(const Paralelogram& romb);
    virtual ~Paralelogram();

    // operator=
    Paralelogram& operator=(const Paralelogram& paralelogram) {
        Dreptunghi::stanga_jos = paralelogram.Dreptunghi::stanga_jos;
        colt_opus = paralelogram.colt_opus;
        Dreptunghi::latura = paralelogram.Dreptunghi::latura;
        latura2 = paralelogram.latura2;
        Dreptunghi::valid = paralelogram.Dreptunghi::valid;
        return *this;
    }
    // operator>>
    friend std::istream& operator>>(std::istream& in, Paralelogram& paralelogram);
    // operator<<
    friend std::ostream& operator<<(std::ostream& out, Paralelogram& paralelogram);
    
    void Afisare(std::ostream& out);
    void Afisare();
    int checkIfValid();
    int getValid();

    float Perimetru();
    float Arie();
};

#endif // PROIECT2_PARALELOGRAM_H