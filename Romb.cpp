#include "Romb.h"

// Constructor neparametrizat
Romb::Romb() {
    this -> stanga_jos = stanga_jos;
    this -> colt_opus = colt_opus;
    this -> latura = 0;
    this -> valid = 0;
    // std::cout << "Neparametrizat - Romb" << std::endl;
}
// Constructor parametrizat
Romb::Romb (Punct stanga_jos, Punct colt_opus, float latura) {
    this -> stanga_jos = stanga_jos;
    this -> colt_opus = colt_opus;
    this -> latura = latura;
    float diagonala1 = Punct::distanta(stanga_jos, colt_opus),
        diagonala2 = sqrt(pow(diagonala1 / 2, 2) - pow(latura, 2)) * 2;
    // Daca diagonalele nu au aceeasi lungime, atunci figura data nu e patrat, deci e romb, deci valid = 1
    this -> valid = !(diagonala1 == diagonala2);
    // std::cout << "Parametrizat - Romb" << std::endl;
}
// Destructor
Romb::~Romb() {
    // std::cout << "Destructor - Romb" << std::endl;
}
// Constructor de copiere
Romb::Romb(const Romb& romb) {
    stanga_jos = romb.stanga_jos;
    colt_opus = romb.colt_opus;
    latura = romb.latura;
    valid = romb.valid;
    // std::cout << "Copiere - Romb" << std::endl;
}
// operator>>
std::istream& operator>>(std::istream& in, Romb& romb) {
    in >> dynamic_cast<Patrat&>(romb);
    in >> romb.colt_opus;
    float diagonala1 = round(Punct::distanta(romb.stanga_jos, romb.colt_opus) * 100) / 100,
        diagonala2 = (round((sqrt(pow(romb.latura, 2) - pow(diagonala1 / 2, 2))) * 100) / 100) * 2;
    romb.valid = romb.checkIfValid(diagonala1, diagonala2);
    return in;
}
// operator<<
std::ostream& operator<<(std::ostream& out, Romb& romb) {
    romb.Afisare();
    return out;
}

void Romb::Afisare(std::ostream& out) {
    out << "ROMB:" << std::endl;
    if (!valid) std::cout << "Datele introduse nu sunt corecte." << std::endl;
    float x1 = stanga_jos.getCoordonataX(),
        y1 = stanga_jos.getCoordonataY(),
        x2 = colt_opus.getCoordonataX(),
        y2 = colt_opus.getCoordonataY();
    out << "stanga_jos: (" << x1 << ", " << y1 << ") colt_opus: (" << x2 << ", " << y2 << ") latura: " << latura << std::endl;
}
void Romb::Afisare() {
    Afisare(std::cout);
}
int Romb::checkIfValid(float const diagonala1, float const diagonala2) {
    // Daca latura este mai mica decat oricare dintre diagonala1 / 2 sau diagonala2 / 2, atunci cateta
    // este mai mare decat ipotenuza, deci, datele introduse nu sunt corecte.
    if (latura < (diagonala1 / 2) or latura < (diagonala2 / 2))
        return 0;
    // Daca diagonalele sunt egale, atunci este patrat, nu romb
    return !(diagonala1 == diagonala2);
}

int Romb::getValid() {
    return valid;
}

float Romb::Perimetru() {
    std::cout << "Perimetrul rombului: ";
    return 4 * latura;
}
float Romb::Arie() {
    std::cout << "Aria rombului: ";
    float diagonala1 = round(Punct::distanta(stanga_jos, colt_opus) * 100) / 100,
        diagonala2 = (round((sqrt(pow(latura, 2) - pow(diagonala1 / 2, 2))) * 100) / 100) * 2;
    return (diagonala1 * diagonala2) / 2;
}