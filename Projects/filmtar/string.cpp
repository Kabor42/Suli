//
// Created by kabor on 2018.03.22..
//

#include "string.hpp"

String::String() {
    length = 0;
    data = new char[length + 1];
    data[length] = '\0';
}

String::String( size_t len) {
    length = len;
    data = new char[length + 1];
    data[length] = '\0';
}

String::String( const char * str) {
    length = strlen(str);
    data = new char[length + 1];
    strcpy( data, str);
}

String::String( const String & str) {
    length = str.length;
    data = new char[length + 1];
    strcpy( data, str.data);
}

String::~String() {
    delete[] data;
}

void String::swap( String & str) {
    std::swap( data, str.data);
    std::swap( length, str.length);
}

String & String::operator = ( String str) {
    swap( str);
    return *this;
}

String String::operator + ( const String & str) {
    String tmp( length + str.length);
    strcpy( tmp, this->data);
    strcpy( tmp, str.data);
    return tmp;
}

size_t String::len() {
    return length;
}

char* String::getPointer() {
    return data;
}

const char* String::getCPointer() {
    return data;
}

char & String::operator [] ( size_t idx) {
    return data[idx];
}

const char & String::operator [] ( size_t idx) const {
    return data[idx];
}

String::operator char*() const {
    return data;
}

bool String::operator == ( const String & str) {
    return (0 == strcmp( data, str.data));
}

bool String::operator != ( const String & str) {
    return ( 0 != strcmp( data, str.data));
}

bool String::operator >  ( const String & str) {
    return ( 0 < strcmp( data, str.data));
}
bool String::operator <  ( const String & str) {
    return ( 0 > strcmp( data, str.data));
}
bool String::operator <= ( const String & str) {
    return ( 0 >= strcmp( data, str.data));
}
bool String::operator >= ( const String & str) {
    return ( 0 <= strcmp( data, str.data));
}


