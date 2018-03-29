#include "ustring.h"

bool UString::isUpper = false;

UString::UString(const UString & us) {
  len = us.len;
  str = new char[len];
  strcpy(str, us.str);
}

UString::UString(const char ch) {
  len = 2;
  str = new char[len];
  str[0] = ch; str[1] = '\0';
}

UString::UString(const char * ch) {
  len = strlen(ch);
  str = new char[len];
  for(size_t i=0; i<len; i++)
    str[i] = ch[i];
  str[len] = '\0';
}

UString::~UString() {
    delete[] str;
}

const char* UString::c_str() const{
  if (str)
    return str;
  return "";
}

size_t UString::size() const {
  return len;
}

char & UString::operator [] (size_t id) {
  if(id >= len) {
    throw "Index out of bounds";
  }
  return str[id];
}

const char & UString::operator [] (size_t id) const {
  if(id >= len) {
    throw "Index out of bounds";
  }
  return str[id];
}

UString & UString::operator = (const UString & us) {
  if (this != &us) {
    len = us.len;
    delete[] str;
    str = new char[len+1];
    strcpy(str,us.str);
  }
  return *this;
}

UString UString::operator + (const UString & us) const {
  UString tmp;
  tmp.len = this->len + us.len;
  delete[] tmp.str;
  tmp.str = new char[len+1];
  strcpy(tmp.str, this->str);
  strcat(tmp.str, us.str);
  return tmp;
}

UString UString::operator + (char ch) const {
  return *this + UString(ch);
}

UString operator + (char ch, const UString & us) {
  return UString(ch) + us;
}

std::ostream & operator << (std::ostream & os, const UString & us) {
  return os << us.c_str();
}

std::istream & operator >> (std::istream & is, UString & us) {
  unsigned char in;
  us = UString("");
  std::ios_base::fmtflags ff = is.flags();
  is.setf(std::ios_base::skipws);
  while (is >> in) {
    is.unsetf(std::ios_base::skipws);
    if(isspace(in)) {
      is.putback(in);
      break;
    } else {
      us = us + in;
    }
  }
  is.setf(ff);
  return is;
}



