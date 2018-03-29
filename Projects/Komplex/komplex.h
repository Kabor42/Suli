//
// Created by kabor on 2018.02.27..
//

#ifndef KOMPLEX_KOMPLEX_H
#define KOMPLEX_KOMPLEX_H

#include <ostream>

class Komplex {
    double re, im;
public:
    Komplex(double re = 0, double im = 0);

    double getRe() { return re; }

    double getRe() const;

    double getIm() const;

    void setRe(double re);

    void setIm(double im);

    bool operator==(const Komplex &k) const;

    bool operator!=(const Komplex &k) const;

    Komplex operator+(const Komplex &k) const;

    Komplex operator+(double d) const;

    Komplex &operator+=(const Komplex &k);

    Komplex &operator+=(double d);

    double abs() const;

    Komplex operator~() const;

    Komplex operator*(const Komplex &k) const;

    Komplex operator*(double d) const;

    Komplex &operator*=(const Komplex &k);

    Komplex &operator*=(double d);
};

Komplex operator+(double d, const Komplex &k);

Komplex operator*(double d, const Komplex &k);

std::ostream &operator<<(std::ostream &os, const Komplex &k);

std::istream &operator>>(std::istream &is, Komplex &k);

#endif //KOMPLEX_KOMPLEX_H