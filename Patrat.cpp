#include "Patrat.h"

// Constructor neparametrizat
Patrat::Patrat() {
    this -> stanga_jos = stanga_jos;
    this -> latura = 0;
    this -> valid = 0;
    // std::cout << "Neparametrizat - Patrat" << std::endl;
}
// Constructor parametrizat
Patrat::Patrat(Punct stanga_jos, float latura) {
    this -> stanga_jos = stanga_jos;
    this -> latura = latura;
    this -> valid = 1;
    // std::cout << "Parametrizat - Patrat" << std::endl;
}
// Destructor
Patrat::~Patrat() {
    // std::cout << "Destructor - Patrat" << std::endl;
}
// Constructor de copiere
Patrat::Patrat(const Patrat& patrat) {
    stanga_jos = patrat.stanga_jos;
    latura = patrat.latura;
    valid = patrat.valid;
    // std::cout << "Copiere - Patrat" << std::endl;
}
// operator>>
std::istream& operator>>(std::istream& in, Patrat& patrat) {
    in >> patrat.stanga_jos;
    std::cout << "Dati latura: ";
    in >> patrat.latura;
    patrat.valid = 1;
    return in;
}
// operator<<
std::ostream& operator<<(std::ostream& out, Patrat& patrat) {
    patrat.Afisare();
    return out;
}

void Patrat::Afisare(std::ostream& out) {
    out << "PATRAT:" << std::endl;
    if (!valid) std::cout << "Datele introduse nu sunt corecte." << std::endl;
    float x = stanga_jos.getCoordonataX(),
        y = stanga_jos.getCoordonataY();
    out << "stanga_jos: (" << x << ", " << y << ") latura: " << latura <<  std::endl;
}
void Patrat::Afisare() {
    Afisare(std::cout);
}

int Patrat::getValid() {
    return valid;
}

float Patrat::Perimetru() {
    std::cout << "Perimetrul patratului: ";
    return 4 * latura;
}
float Patrat::Arie() {
    std::cout << "Aria patratului: ";
    return latura * latura;
}
