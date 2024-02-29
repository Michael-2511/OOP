#ifndef PROIECT2_DREPTUNGHI_H
#define PROIECT2_DREPTUNGHI_H

#include "Patrat.h"

class Dreptunghi: virtual public Patrat {
protected:
    float latura2;
    int valid;
public:
    Dreptunghi();
    Dreptunghi (Punct stanga_jos, float latura, float latura2);
    Dreptunghi(const Dreptunghi& dreptunghi);
    virtual ~Dreptunghi();

    // operator=
    Dreptunghi& operator=(const Dreptunghi& dreptunghi) {
        stanga_jos = dreptunghi.stanga_jos;
        latura = dreptunghi.latura;
        latura2 = dreptunghi.latura;
        valid = dreptunghi.valid;
        return *this;
    }
    // operator>>
    friend std::istream& operator>>(std::istream& in, Dreptunghi& dreptunghi);
    // operator<<
    friend std::ostream& operator<<(std::ostream& out, Dreptunghi& dreptunghi);

    void Afisare(std::ostream& out);
    void Afisare();
    int checkIfValid();
    int getValid();

    float Perimetru();
    float Arie();
};

#endif // PROIECT2_DREPTUNGHI_H