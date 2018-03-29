#include <iostream>
#include "film.hpp"
#include "dokumentum.hpp"
#include "csaladi.hpp"
#include "filmek.hpp"

#include "hetColl.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Film lotrI("A gyűrűk Ura: A gyűrű szövetsége", 218, 2001);
    Film lotrII("A gyűrűk Ura: A két torony", 219, 2002);
    Film lotrIII("A gyűrűk Ura: A király visszatér", 135, 2003);

    Csaladi stuart("Stuart Little", 84, 1994, 12);

    Dokumentum wwc("A Wild Wild Country", 120, 2018, "When the world's most controversial guru builds a utopian city deep in the Oregon desert, conflict with the locals escalates into a national scandal. A true story.");

    Filmek csoport;

    std::cout << "Filmek( csoport ) elkeszult" << std::endl;

    csoport.addNew(lotrI);
    csoport.addNew(lotrII);
    csoport.addNew(lotrIII);
    csoport.addNew(wwc);
    csoport.addNew(stuart);

    std::cout << csoport << std::endl;

    hetColl biz;

    std::cout << " Biz is empty?: ";
    std::cout << (biz.isEmpty()) ? "true" : "false";
    std::cout << std::endl;

    biz.push(lotrI);

    std::cout << " Biz is empty?: ";
    std::cout << (biz.isEmpty()) ? "true" : "false";
    std::cout << std::endl;

    std::cout << "Benne van-e LotrI?: ";
    std::cout << (biz.isIn(lotrI)) ? "true" : "false";
    std::cout << std::endl;

    biz.push(lotrII);
    biz.push(lotrIII);
    biz.push(wwc);
    biz.push(stuart);

    std::cout << "Benne van-e WWC?: ";
    std::cout << (biz.isIn(wwc)) ? "true" : "false";
    std::cout << std::endl;

    std::cout << biz << std::endl;

    biz.del(lotrIII);

    std::cout << biz << std::endl;


    return 0;
}