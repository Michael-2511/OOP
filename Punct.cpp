#include "Punct.h"

// Constructor neparametrizat 
Punct::Punct(): x(0), y(0) {
    // std::cout << "Neparametrizat - Punct" << std::endl;
}
// Constructor parametrizat
Punct::Punct(float x, float y): x(x), y(y) {
    // std::cout << "Parametrizat - Punct" << std::endl;
}
// Destructor
Punct::~Punct() {
    // std::cout << "Destructor - Punct" << std::endl;
}
// Constructor de copiere
Punct::Punct(const Punct& punct) {
    x = punct.x; 
    y = punct.y;
    // std::cout << "Copiere - Punct" << std::endl;
}
// operator>>
std::istream& operator>>(std::istream& in, Punct& punct) {
    std::cout << "Dati coordonatele: " << std::endl;
    in >> punct.x;
    in >> punct.y;
    return in; 
}
// operator<<
std::ostream& operator<<(std::ostream& out, Punct& punct) {
    punct.Afisare();
    return out;
}

void Punct::Afisare(std::ostream& out) {
    out << "Punct - (" << x  << ", "<< y << ")" << std::endl;
}
void Punct::Afisare() {
    Afisare(std::cout);
}

int Punct::getValid() {
    return valid;
}

float Punct::getCoordonataX() {
    return x;
}
float Punct::getCoordonataY() {
    return y;
}

void Punct::setPunct(Punct punct) {
    this -> x = punct.x;
    this -> y = punct.y;
}

// functie de aflare a distantei
float Punct::distanta(const Punct& A, const Punct& B) {
    return sqrt(pow(B.x - A.x, 2) + (pow(B.y - A.y, 2)));
}

std::string Punct::Perimetru() {
    return "Punctul nu are perimetru.";
}

std::string Punct::Arie() {
    return "Punctul nu are arie.";
}


