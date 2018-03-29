//
// Created by kabor on 2018.03.29..
//

#include "hetColl.hpp"

hetColl::hetColl(unsigned int var) {
    in = var;
    arr = new Film[in];
}

hetColl &hetColl::operator=(const hetColl & ref) {
    if ( this != &ref )
    {
        in = ref.in;
        delete[] arr;
        arr = new Film[in];
        for(unsigned int i=0; i<in; i++)
            arr[i] = ref.arr[i];
    }
    return *this;
}

hetColl::~hetColl() {
    delete[] arr;
}

unsigned int hetColl::size() const {
    return in;
}

Film &hetColl::operator[](unsigned int id) {
    return arr[id];
}

const Film &hetColl::operator[](unsigned int id) const {
    return arr[id];
}

void hetColl::push(Film & f) {
    unsigned int newIn = this->in + 1;
    Film *tmp = new Film[newIn];
    for (unsigned int i = 0; i < this->in; i++) {
        tmp[i] = this->arr[i];
    }
    tmp[newIn - 1] = f;
    delete[] arr;
    arr = tmp;
    in = newIn;
}

Film &hetColl::pop() {
    unsigned int newIn = this->in - 1;
    unsigned i = 0;
    Film *retVal = new Film;
    Film *tmp = new Film[newIn];
    for (i=0; i < newIn; i++)
        tmp[i] = this->arr[i];
    *retVal = this->arr[newIn];
    delete[] this->arr;
    arr = tmp;
    return *retVal;
}

void hetColl::del(Film & f) {
    unsigned int delID = this->in + 10;
    unsigned int i=0, j=0;

    for(i=0; i<this->in; i++){
        if(this->arr[i] == f) {
            delID = i;
            break;
        }
    }
    if (this->in + 10 != delID){
        unsigned int newIn = this->in - 1;
        Film *tmp = new Film[newIn];
        i=0;
        j=0;
        while(j<newIn) {
            if(i == delID)
                i++;
            tmp[j++] = this->arr[i++];
        }
        delete[] this->arr;
        arr = tmp;
    }
}

bool hetColl::isEmpty() const {
    if (in == 0 || arr == NULL)
        return true;
    return false;
}

bool hetColl::isIn(Film & f) const {
    for(unsigned int i=0; i< this->in; i++)
        if( this->arr[i] == f)
            return true;
    return false;
}

std::ostream &hetColl::printAll(std::ostream & os) {
    for(unsigned int i=0; i<this->in; i++)
        os << this->arr[i];
    return os;
}

void hetColl::save() {

}

void hetColl::read() {

}

std::ostream & operator << (std::ostream & os, hetColl & hc) {
    return hc.printAll(os);
}
