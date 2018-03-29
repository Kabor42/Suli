#ifndef EMBER_H_INCLUDED
#define EMBER_H_INCLUDED
#include <cstring>

class Ember{
protected:
    char* nev;
    int szulEv;

public:

    Ember() :szulEv(1999){

    nev = new char[7];
    strcpy(nev, "EH9JTC");

    };

    Ember(const char* n, int ev);

    Ember(const Ember& e);

    Ember& operator=(const Ember& e);

    const char* getNev() const;

    virtual int getKor(int ev) const;

    virtual const char* foglalkozas() const;

    virtual ~Ember();

};

#endif // EMBER_H_INCLUDED
