#ifndef PROIECT2_TRAPEZ_H
#define PROIECT2_TRAPEZ_H

#include "Paralelogram.h"

class Trapez: public Paralelogram {
protected:
    float baza2;
public:
    Trapez();
    Trapez (Punct stanga_jos, Punct colt_opus, float latura, float latura2, float baza2);
    Trapez(const Trapez& trapez);
    virtual ~Trapez();

    // operator=
    Trapez& operator=(const Trapez& trapez) {
        Dreptunghi::stanga_jos = trapez.Dreptunghi::stanga_jos;
        colt_opus = trapez.colt_opus;
        Dreptunghi::latura = trapez.Dreptunghi::latura;
        latura2 = trapez.Dreptunghi::latura;
        baza2 = trapez.baza2;
        Dreptunghi::valid = trapez.Dreptunghi::valid;
        return *this;
    }
    // operator>>
    friend std::istream& operator>>(std::istream& in, Trapez& trapez);
    // operator<<
    friend std::ostream& operator<<(std::ostream& out, Trapez& trapez);

    void Afisare(std::ostream& out);
    void Afisare();
    int checkIfValid();
    int getValid();

    float getIpotenuza(float cateta1, float cateta2);
    float getCateta(float ipotenuza, float cateta);
    float getInaltime(Punct punct1, Punct punct2);

    float Perimetru();
    float Arie();
};

#endif // PROIECT2_TRAPEZ_H