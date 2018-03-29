// Elvisz
// ne FELEJTSD A HEADER GUARDOKAT

#include <iostream>   // cout
#include <cstring>    // strlen, strcpy, strcat, strcmp
#include <algorithm>  // swap

class String {
  size_t length;
  char* data;

public:
  // Konstruktorok és destruktor
  String(size_t length = 0)   : length(length),   data(new char[length+1]) { data[length] = '\0'; }
  String(const char* str)     : length(strlen(str)),  data(new char[length+1]) { strcpy(data, str); }
  String(const String&amp; other) : length(other.length), data(new char[length+1]) { strcpy(data, other.data); }
  virtual ~String () { delete[] data; }

  // Copy-and-swap
  void swap(String&amp; other) {
    std::swap(data, other.data);
    std::swap(length, other.length);
  }

  String&amp; operator= (String other) {
    swap(other);
    return *this;
  }

  // Getterek és setterek
  size_t     getLength()   const { return length; }
  char*      getPointer()  const { return data; }
  const char*  getCPointer() const { return data; }

  // Operátorok
  // Indexelő
  char&amp; operator[](size_t index) { return data[index]; }
  const char&amp; operator[](size_t index) const { return data[index]; }

  // Castoló
  operator char*() const { return data; }

  // Összefűző
  String operator+(const String&amp; other) {
    String temp(length + other.length);
    strcpy(temp.data, data);
    strcat(temp.data, other.data);
    return temp;
  }

  // Összehasonlító
  bool operator==(const String&amp; other) { return (strcmp(data, other.data) == 0); }
  bool operator!=(const String&amp; other) { return (strcmp(data, other.data) != 0); }
  bool operator< (const String&amp; other) { return (strcmp(data, other.data) <  0); }
  bool operator> (const String&amp; other) { return (strcmp(data, other.data) >  0); }
  bool operator>=(const String&amp; other) { return (strcmp(data, other.data) >= 0); }
  bool operator<=(const String&amp; other) { return (strcmp(data, other.data) <= 0); }

};
