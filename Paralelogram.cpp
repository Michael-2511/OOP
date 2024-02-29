#include "Paralelogram.h"

// Constructor neparametrizat
Paralelogram::Paralelogram() {
    this -> Dreptunghi::stanga_jos = Dreptunghi::stanga_jos;
    this -> colt_opus = colt_opus;
    this -> Dreptunghi::latura = 0;
    this -> latura2 = 0;
    this -> Dreptunghi::valid = 0;
    // std::cout << "Neparametrizat - Paralelogram" << std::endl;
}
// Constructor parametrizat
Paralelogram::Paralelogram (Punct stanga_jos, Punct colt_opus, float latura, float latura2) {
    this -> Dreptunghi::stanga_jos = stanga_jos;
    this -> colt_opus = colt_opus;
    this -> Dreptunghi::latura = latura;
    this -> latura2 = latura2;
    this -> Dreptunghi::valid = checkIfValid();
    // std::cout << "Parametrizat - Paralelogram" << std::endl;
}
// Destructor
Paralelogram::~Paralelogram() {
    // std::cout << "Destructor - Paralelogram" << std::endl;
}
// Constructor de copiere
Paralelogram::Paralelogram(const Paralelogram& paralelogram) {
    Dreptunghi::stanga_jos = paralelogram.Dreptunghi::stanga_jos;
    colt_opus = paralelogram.colt_opus;
    Dreptunghi::latura = paralelogram.Dreptunghi::latura;
    latura2 = paralelogram.latura2;
    Dreptunghi::valid = paralelogram.Dreptunghi::valid;
    // std::cout << "Copiere - Paralelogram" << std::endl;
}
// operator>>
std::istream& operator>>(std::istream& in, Paralelogram& paralelogram) {
    in >> dynamic_cast<Dreptunghi&>(paralelogram);
    in >> paralelogram.colt_opus;
    paralelogram.Dreptunghi::valid = paralelogram.checkIfValid();
    return in;
}
// operator<<
std::ostream& operator<<(std::ostream& out, Paralelogram& paralelogram) {
    paralelogram.Afisare();
    return out;
}

void Paralelogram::Afisare(std::ostream& out) {
    out << "PARALELOGRAM:" << std::endl;
    if (!Dreptunghi::valid) std::cout << "Datele introduse nu sunt corecte." << std::endl;
    float x1 = Dreptunghi::stanga_jos.getCoordonataX(),
        y1 = Dreptunghi::stanga_jos.getCoordonataY(),
        x2 = colt_opus.getCoordonataX(),
        y2 = colt_opus.getCoordonataY();
    out << "stanga_jos: (" << x1 << ", " << y1 << ") colt_opus: (" << x2 << ", " << y2 << ") latura: " 
        << Dreptunghi::latura << " latura2: " << latura2 << std::endl;
}
void Paralelogram::Afisare() {
    Afisare(std::cout);
}
int Paralelogram::checkIfValid() {
    float x_stanga_sus_out = Dreptunghi::stanga_jos.getCoordonataX(),
        y_stanga_sus_out = colt_opus.getCoordonataY();
    Punct stanga_sus_out(x_stanga_sus_out, y_stanga_sus_out);
    float inaltime = Punct::distanta(Dreptunghi::stanga_jos, stanga_sus_out);
    // Daca inaltimea este egala cu latura sau latura2, atunci figura este patrat/dreptunghi
    if (inaltime == Dreptunghi::latura or inaltime == latura2)
        return 0;
    // Daca laturile sunt egale, atunci figura este patrat
    return !(Dreptunghi::latura == latura2);
}

int Paralelogram::getValid() {
    return valid;
}

float Paralelogram::Perimetru() {
    std::cout << "Perimetrul paralelogramului: ";
    return 2 * Dreptunghi::latura + 2 * latura2;
}
float Paralelogram::Arie() {
    std::cout << "Aria paralelogramului: ";
    float x_dreapta_jos_out = colt_opus.getCoordonataX(),
        y_dreapta_jos_out = Dreptunghi::stanga_jos.getCoordonataY();
    Punct dreapta_jos_out(x_dreapta_jos_out, y_dreapta_jos_out);
    float inaltime = Punct::distanta(colt_opus, dreapta_jos_out);
    return inaltime * latura2;
}