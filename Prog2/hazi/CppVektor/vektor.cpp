#include "vektor.h"

const char *exc = "M8CFQC";

size_t Vektor::defSize = 21;
double Vektor::defValue = 21;

Vektor::Vektor(const Vektor& v) {
    nElements = v.nElements;
    pVec = new double[nElements];
    for(size_t i=0; i<nElements; i++) {
        pVec[i] = v.pVec[i];
    }
}

Vektor::~Vektor() {
    delete[] pVec;
}

Vektor& Vektor::operator=(const Vektor& v) {
    if (this != &v) {
        nElements = v.nElements;
        delete[] this->pVec;
        pVec = new double[nElements];
        for(size_t i=0; i<nElements; i++) {
            pVec[i] = v.pVec[i];
        }
    }
    return *this;
}

double& Vektor::operator[](size_t idx) {
    if(idx >= nElements)
        throw exc;
    return (pVec[idx]);
}

const double& Vektor::operator[](size_t idx) const {
    if(idx >= nElements)
        throw exc;
    return (pVec[idx]);
}

Vektor operator*(double val, const Vektor& vec) {
    Vektor v(vec);
    for (size_t i=0; i<v.size(); i++) {
        v[i] *= val;
    }
    return v;
}
