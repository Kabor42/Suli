---
title: "NagyHF specifikáció - Filmtár"
author: "Nagy Dominik"
date: 2018.03.24.
titlepage: true
---

# Leírás

A program egy filmeket tároló adatbázis lesz.
Tárolni szeretném a következő információkat:

 * film címe
 * kiadási év
 * lejátszási idő
 * műfaj

Abban az esetben, ha a film bizonyos specifikus műfajba tartozik (Dokumentum, Családi, Animációs, Akció ...),
a műfaja szerinti származtatott osztályba kerülnének.
Így műfaj specifikus adatokat tárolnám:

 * Dokumentum film:
    * Leírás
    * Narrátor
    * Típus: természetfilm...
 * Családi:
    * Korhatár
 * Animációs:
    * Animációs stúdió
 * Akció:
    * Korhatár
    * Szereplőgárda

A tárolásra egy generikus osztályt szeretnék alkalmazni, ami tetszőleges típusú lehet.

# Műveletek

Az adatbázis alapvető műveleteit szeretném megírni, ami:

 * Adatbázis létrehozása / törlése
 * Film felvétele / törlése
 * Keresés tetszőleges kritérium szerint
 * Rendezés tetszőleges kritérium szerint
 * Fájlba írás/olvasás

# Tesztek

A létrehozott objektumokhoz olyan teszteket szeretnék írni, amik vizsgálják az operációk helyes/helytelen működését.
Ezek lehetnek, helyesen megadott adatok, helytelenül használt paraméterek. 
Ilyen esetekben a kivételkezelések helyességéről is szeretnék megbizonyosodni.

Minden objektumhoz saját tesztfájl tartozna. És lenne egy globális teszt is, ami az egész program működését és tesztjeit szemléltetné.

# Felhasználói környezet

A program maga teljesen szöveges környezetben futna.
Ha lesz elég időm, akkor egy ncurses interfészt szeretnék implementálni, kizárólag csak az olvashatóság kedvéért.
Egyébként minden felhasználói interakció a szabványos kimenetre íródna, hibaüzenetek a szabványos hibakimenetre.

A program erősen menüorientált lenne.
