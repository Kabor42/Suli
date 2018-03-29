/**
 *
 * \file string2.cpp
 *
 * Itt kell megvalósítania a hiányzó tagfüggvényeket.
 * Segítségül megadtuk a C++ nem OO eszközeinek felhasználásával készített String-kezelő
 * függvényke neveit.
 *
 * Ha valamit INLINE-ként valósít meg, akkor annak a string5.h-ba kell kerülnie,
 * akár kívül akár osztályon belül definiálja. (Az inline függvényeknek minden
 * fordítási egységben elérhetőknek kell lenniük)
 * *
 * A teszteléskor ne felejtse el beállítani a string5.h-ban állományban az ELKESZULT makrót.
 *
 */

#ifdef _MSC_VER
// MSC ne adjon figyelmeztető üzenetet a C sztringkezelő függvényeire
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>             // Kiíratáshoz
#include <cstring>              // Sztringműveletekhez

#include "memtrace.h"           // a standard headerek után kell lennie
#include "string5.h"


/// Konstruktorok: egy char karakterből (createString)
///                egy nullával lezárt char sorozatból (createString)
String::String() {
    pData = new char[1];
    pData[0] = '\0';
    len = 0;
}

String::String(size_t s) {
    len = s;
    pData = new char[len+1];
    pData[0] = '\0';
}

String::String(const char s) {
    pData = new char[2];
    pData[0] = s; pData[1] = '\0';
    len = 1;
}

String::String(const char *str) {
    len = strlen(str);
    pData = new char[len+1];
    strcpy(pData, str);
}

/// Másoló konstruktor: String-ből készít (createString)
String::String(const String& s) {
    len = s.len;
    pData = new char[len];
    strcpy(pData, s.pData);
}

/// Destruktor (disposeString)
String::~String() {
    delete[] pData;
}

/// operator=

String& String::operator= (String o) {
    swap(o);
    return *this;
}

/// [] operátorok: egy megadott indexű elem REFERENCIÁJÁVAL térnek vissza (charAtString)
/// indexhiba esetén const char * kivételt dob!
char& String::operator[] (size_t idx) {
    if(idx>=len)
        throw std::out_of_range("");
    return pData[idx];
}

const char& String::operator[] (size_t idx) const {
    if(idx>=len)
        throw std::out_of_range("");
    return pData[idx];
}

/// + operátorok:
///                 String-hez jobbról karaktert ad (addString)
///                 String-hez String-et ad (addString)
String String::operator+ (const String& o) const {
    String tmp(len + o.len + 1);
    strcpy(tmp.pData, pData);
    strcat(tmp.pData, o.pData);
    return tmp;
}

String String::operator+ (const char ch) {
    String tmp = *this + String(ch);
    return tmp;
}

String operator+(const char ch, const String& str) {
    String tmp(ch);
    tmp = tmp + str;
    return tmp;
}

/// << operator, ami kiír az ostream-re

std::ostream& operator<<(std::ostream& os, const String& str) {
    for(size_t i = 0; i < str.size(); i++)
        os << str[i];
    return os;
}


/// >> operátor, ami beolvas az istream-ről egy szót
