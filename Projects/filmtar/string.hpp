//
// Created by kabor on 2018.03.22..
//

#ifndef FILMTAR_STRING_HPP
#define FILMTAR_STRING_HPP

#include <iostream>
#include <cstring>
#include <algorithm>

class String {
private:
    size_t length;
    char *data;
public:
    String();
    String( size_t);
    String( const char *);
    String( const String &);
    virtual ~String();

    void swap( String & str);

    String& operator = ( String str);
    String operator + ( const String & str);


    size_t len();
    char* getPointer();
    const char* getCPointer();

    char & operator [] ( size_t idx);
    const char & operator [] ( size_t idx) const;

    operator char*() const;

    bool operator == ( const String & str);
    bool operator != ( const String & str);
    bool operator >  ( const String & str);
    bool operator <  ( const String & str);
    bool operator <= ( const String & str);
    bool operator >= ( const String & str);
};



#endif //FILMTAR_STRING_HPP
