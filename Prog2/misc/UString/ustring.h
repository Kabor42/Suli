#ifndef USTRING_H
#define USTRING_H

#include <iostream>
#include <cstring>

class UString {
  char *str;
  size_t len;
  static bool isUpper;
public:

  UString() :str(0),len(0) {}
  UString(const UString &);
  UString(char);
  UString(const char *);
  virtual ~UString();

  const char* c_str() const;

  size_t size() const;
  char& operator [] (size_t);
  const char& operator [] (size_t) const;

  UString& operator = (const UString &);
  UString operator + (const UString &) const;
  UString operator + (char) const;

  static bool UCase() { return isUpper; }
  static void UCase(bool a) { isUpper = a; }

};

UString operator + (char, const UString&);
std::ostream & operator << (std::ostream &, const UString &);
std::istream & operator >> (std::istream &, UString &);


#endif // USTRING_H
