#ifndef PROIECT2_PUNCT_H
#define PROIECT2_PUNCT_H

#include <iostream>
#include <cmath>

class Punct {
private:
public:
    //int valid;    // cred ca trebuie sters
protected:
    const int valid = 1;
    float x, y;
public:
    // Constructor neparametrizat 
    Punct();
    // Constructor parametrizat
    Punct(float x, float y);
    // Destructor
    virtual ~Punct();
    // Constructor de copiere
    Punct(const Punct& punct);
    // operator=
    Punct& operator=(const Punct& punct) {
        x = punct.x;
        y = punct.y;
        return *this;
    }
    // operator>>
    friend std::istream& operator>>(std::istream& in, Punct& punct);
    // operator<<
    friend std::ostream& operator<<(std::ostream& out, Punct& punct);

    virtual void Afisare(std::ostream& out);
    virtual void Afisare();

    virtual int checkIfValid() {}
    virtual int getValid();

    virtual float getIpotenuza() {}
    virtual float getCateta() {}

    std::string Perimetru();
    std::string Arie();

    float getCoordonataX();
    float getCoordonataY();

    void setPunct(Punct punct);

    static float distanta(const Punct& A, const Punct& B);
};

#endif // PROIECT2_PUNCT_H
