#include "Trapez.h"

// Constructor neparametrizat
Trapez::Trapez() {
    this -> Dreptunghi::stanga_jos = Dreptunghi::stanga_jos;
    this -> colt_opus = colt_opus;
    this -> Dreptunghi::latura = 0;
    this -> latura2 = 0;
    this -> baza2 = 0;
    this -> Dreptunghi::valid = 0;
    // std::cout << "Neparametrizat - Trapez" << std::endl;
}
// Constructor parametrizat
Trapez::Trapez (Punct stanga_jos, Punct colt_opus, float latura, float latura2, float baza2) {
    this -> Dreptunghi::stanga_jos = stanga_jos;
    this -> colt_opus = colt_opus;
    this -> Dreptunghi::latura = latura;
    this -> latura2 = latura2;
    this -> baza2 = baza2;
    this -> Dreptunghi::valid = !(latura == latura2);
    // std::cout << "Parametrizat - Trapez" << std::endl;
}
// Destructor
Trapez::~Trapez() {
    // std::cout << "Destructor - Trapez" << std::endl;
}
// Constructor de copiere
Trapez::Trapez(const Trapez& trapez) {
    Dreptunghi::stanga_jos = trapez.Dreptunghi::stanga_jos;
    colt_opus = trapez.colt_opus;
    Dreptunghi::latura = trapez.Dreptunghi::latura;
    latura2 = trapez.latura2;
    baza2 = trapez.baza2;
    Dreptunghi::valid = trapez.Dreptunghi::valid;
    // std::cout << "Copiere - Trapez" << std::endl;
}
// operator>>
std::istream& operator>>(std::istream& in, Trapez& trapez) {
    in >> dynamic_cast<Paralelogram&>(trapez);
    std::cout << "Dati baza: ";
    in >> trapez.baza2;
    trapez.Dreptunghi::valid = trapez.checkIfValid();
    return in;
}
// operator<<
std::ostream& operator<<(std::ostream& out, Trapez& trapez) {
    trapez.Afisare();
    return out;
}

void Trapez::Afisare(std::ostream& out) {
    out << "TRAPEZ:" << std::endl;
    if (!Dreptunghi::valid) std::cout << "Datele introduse nu sunt corecte." << std::endl;
    float x1 = Dreptunghi::stanga_jos.getCoordonataX(),
        y1 = Dreptunghi::stanga_jos.getCoordonataY(),
        x2 = colt_opus.getCoordonataX(),
        y2 = colt_opus.getCoordonataY();
    out << "stanga_jos: (" << x1 << ", " << y1 << ") colt_opus: (" << x2 << ", " << y2 << ") latura: " 
        << Dreptunghi::latura << " latura2: " << latura2 << " baza2: " << baza2 << std::endl;
}
void Trapez::Afisare() {
    Afisare(std::cout);
}

int Trapez::checkIfValid() {
    float inaltime = getInaltime(colt_opus, Dreptunghi::stanga_jos);
    // Daca inaltimea este mai mare decat latura, atunci datele introduse nu sunt corecte
    if (inaltime >= Dreptunghi::latura)
        return 0;
    return 1;
}

int Trapez::getValid() {
    return valid;
}


float Trapez::getIpotenuza(float cateta1, float cateta2) {
    return round((sqrt(pow(cateta1, 2) + pow(cateta2, 2))) * 100) / 100;
}

float Trapez::getCateta(float ipotenuza, float cateta) {
    return round((sqrt(pow(ipotenuza, 2) - pow(cateta / 2, 2))) * 100) / 100;
}

float Trapez::getInaltime(Punct punct1, Punct punct2) {
    float x_punct = punct1.getCoordonataX(),
        y_punct = punct2.getCoordonataY();
    Punct punct(x_punct, y_punct);
    return Punct::distanta(punct, punct1);
}

float Trapez::Perimetru() {
    std::cout << "Perimetrul trapezului: ";
    return 2 * Dreptunghi::latura + latura2 + baza2;
}
float Trapez::Arie() {
    std::cout << "Aria trapezului: ";
    float inaltime = getInaltime(colt_opus, Dreptunghi::stanga_jos);
    return ((latura2 + baza2) * inaltime) / 2;
}