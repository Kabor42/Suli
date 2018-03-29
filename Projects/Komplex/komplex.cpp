//
// Created by kabor on 2018.02.27..
//

#include <cmath>
#include <istream>
#include "komplex.h"

Komplex::Komplex(double re, double im) {
    this->re = re;
    this->im = im;
}

double Komplex::getRe() const {
    return re;
}

double Komplex::getIm() const {
    return im;
}

void Komplex::setRe(double re) {
    this->re = re;
}

void Komplex::setIm(double im) {
    this->im = im;
}

double Komplex::abs() const {
    return std::sqrt(
            std::pow(re, 2) + std::pow(im, 2)
    );
}

bool Komplex::operator==(const Komplex &k) const {
    return ((re == k.re) && (im == k.im));
}

bool Komplex::operator!=(const Komplex &k) const {
    return !(*this == k);
}

Komplex Komplex::operator+(const Komplex &k) const {
    return {re + k.re, im + k.im};
}

Komplex Komplex::operator+(double d) const {
    return {re + d, im};
}

Komplex Komplex::operator*(const Komplex &k) const {
    return {re * k.re - im * k.im, re * k.im + im * k.re};
}

Komplex Komplex::operator*(double d) const {
    return {re * d, im * d};
}

Komplex &Komplex::operator+=(const Komplex &k) {
    re = re + k.re;
    im = im + k.im;
    return *this;
}

Komplex &Komplex::operator+=(double d) {
    re = re + d;
    return *this;
}

Komplex &Komplex::operator*=(const Komplex &k) {
    double tmp = re;
    re = tmp * k.re - im * k.im;
    im = tmp * k.im + im * k.re;
    return *this;
}

Komplex &Komplex::operator*=(double d) {
    re = re * d;
    im = im * d;
    return *this;
}

Komplex Komplex::operator~() const {
    return {re, -im};
}

Komplex operator+(double d, const Komplex &k) {
    return {d + k.getRe(), k.getIm()};
}

Komplex operator*(double d, const Komplex &k) {
    return {d * k.getRe(), d * k.getIm()};
}

std::ostream &operator<<(std::ostream &os, const Komplex &k) {
    os << k.getRe();
    if (k.getIm() >= 0)
        os << "+";
    os << k.getIm();
    os << "j";
    return os;
}

std::istream &operator>>(std::istream &is, Komplex &k) {
    double re, im;
    is >> re >> im;
    is.ignore(256, 'j');

    k.setRe(re);
    k.setIm(im);

    return is;
}
