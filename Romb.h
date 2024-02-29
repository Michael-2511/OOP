#ifndef PROIECT2_ROMB_H
#define PROIECT2_ROMB_H

#include "Patrat.h"

class Romb: virtual public Patrat {
protected:
    Punct colt_opus;
    int valid;
public:
    Romb();
    Romb(Punct stanga_jos, Punct colt_opus, float latura);
    Romb(const Romb& romb);
    virtual ~Romb();

    // operator=
    Romb& operator=(const Romb& romb) {
        stanga_jos = romb.stanga_jos;
        colt_opus = romb.colt_opus;
        latura = romb.latura;
        valid = romb.valid;
        return *this;
    }
    // operator>>
    friend std::istream& operator>>(std::istream& in, Romb& romb);
    // operator<<
    friend std::ostream& operator<<(std::ostream& out, Romb& romb);

    void Afisare(std::ostream& out);
    void Afisare();
    int checkIfValid(float const diagonala1, float const diagonala2);
    int getValid();

    float Perimetru();
    float Arie();
};

#endif // PROIECT2_ROMB_H