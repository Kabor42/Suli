#ifndef KIFLI_H
#define KIFLI_H

#include "aru.h"

class Kifli : public Aru
{
    public:
        Kifli(double ar, const char *spec="") :Aru("Kifli", "darab", ar), spec(spec) {}

        std::ostream & 	print (std::ostream &os) const
        {
            return os << megnevezes << " "
                        << spec << "; "
                        << ar << "Ft/"
                        << egyseg;
        }

    private:
        String spec; //!< Member variable "spec"
};

#endif // KIFLI_H
