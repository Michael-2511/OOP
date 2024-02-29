#include "Dreptunghi.h"

// Constructor neparametrizat
Dreptunghi::Dreptunghi() {
    this -> stanga_jos = stanga_jos;
    this -> latura = 0;
    this -> latura2 = 0;
    this -> valid = 0;
    // std::cout << "Neparametrizat - Dreptunghi" << std::endl;
}
// Constructor parametrizat
Dreptunghi::Dreptunghi (Punct stanga_jos, float latura, float latura2) {
    this -> stanga_jos = stanga_jos;
    this -> latura = latura;
    this -> latura2 = latura2;
    this -> valid = !(latura == latura2);
    // std::cout << "Parametrizat - Dreptunghi" << std::endl;
}
// Destructor
Dreptunghi::~Dreptunghi() {
    // std::cout << "Destructor - Dreptunghi" << std::endl;
}
// Constructor de copiere
Dreptunghi::Dreptunghi(const Dreptunghi& dreptunghi) {
    stanga_jos = dreptunghi.stanga_jos;
    latura = dreptunghi.latura;
    latura2 = dreptunghi.latura2;
    valid = dreptunghi.valid;
    // std::cout << "Copiere - Dreptunghi" << std::endl;
}
// operator>>
std::istream& operator>>(std::istream& in, Dreptunghi& dreptunghi) {
    in >> dynamic_cast<Patrat&>(dreptunghi);
    std::cout << "Dati a doua latura: ";
    in >> dreptunghi.latura2;
    dreptunghi.valid = dreptunghi.checkIfValid();
    return in;
}
// operator<<
std::ostream& operator<<(std::ostream& out, Dreptunghi& dreptunghi) {
    dreptunghi.Afisare();
    return out;
}

void Dreptunghi::Afisare(std::ostream& out) {
    out << "DREPTUNGHI:" << std::endl;
    if (!valid) std::cout << "Datele introduse nu sunt corecte." << std::endl;
    float x = stanga_jos.getCoordonataX(),
        y = stanga_jos.getCoordonataY();
    out << "stanga_jos: (" << x << ", " << y << ") latura: " << latura << " latura2: " << latura2 <<  std::endl;
}
void Dreptunghi::Afisare() {
    Afisare(std::cout);
}
// Daca laturile sunt egale, atunci figura este patrat
int Dreptunghi::checkIfValid() {
    return !(latura == latura2);
}

int Dreptunghi::getValid() {
    return valid;
}

float Dreptunghi::Perimetru() {
    std::cout << "Perimetrul dreptunghiului: ";
    return 2 * latura + 2 * latura2;
}
float Dreptunghi::Arie() {
    std::cout << "Aria dreptunghiului: ";
    return latura * latura2;
}