#ifndef EMBER_H_INCLUDED
#define EMBER_H_INCLUDED

#include <cstring>

class Ember {
protected:
    char *nev;
    int szulEv;
public:
    // Ctors
    Ember() :szulEv(1993) {nev=new char[7]; strcpy(nev,"M8CFQC");}
    Ember( const char* n, int ev);
    Ember( const Ember& e);
    virtual ~Ember();
    // Member functions
    Ember& operator=(const Ember& e);
    const char* getNev() const;
    virtual int getKor(int ev) const;
    virtual const char* foglalkozas() const;
};

#endif // EMBER_H_INCLUDED
