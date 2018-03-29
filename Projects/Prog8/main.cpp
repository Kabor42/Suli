/**
 * foprogram az F8 osztaly kiprobalasahoz.
 * Nagy Dominik, M8CFQC reszere
 * Datum: 2018-03-04 15:14:01
 * Ez az allomany tetszes szerint modosithato
 */

#include <iostream>
#include <stdexcept>
#include "f8.hpp"

// tobbszoros include ellenorzese
#include "f8.hpp"

// Csak akkor fordithato, ha nincs a header fajlokban
// 'using namespace std;'
// Ha megis van, valami ilyesmi hibauzenetet kapunk:
// 'reference to .endl. is ambiguous'
namespace nsteszt { int endl; }
void nstesztf() {
    using namespace nsteszt;
    std::cout << endl;
}

using namespace std;

int main() {
    F8<468> vec;
    F8<468> vec2;

    try {
        // Kiirjuk hftest azonosító sorait
        cout << vec.c_str() << endl;		// hftest azonosító sorát adja
        cout << "Feladat = 8" << endl;

        int n = 0;
        double x;
        while(cin >> x) 			// beolvasas, amig tudunk
            vec[n++] = x;

        cout << n << " db szam rendezve:" << endl;
        vec.rendez();				// rendezes

        F8<468> vec3 = vec;			// masolo konstruktor (automatikusan jo)
        vec2 = vec3; 				// ertekadas (automatikusan jo)

        for (int i = 0; i < n; i++) cout << "[" << i+1 << "]" << vec2[i] << endl;
        cout << "-----" << endl;

        F8<30> b;				// 30 elemu
        for (int i = 0; i < 19; i++) b[i] = i-8;// de csak 19-et tesunk bele
        b.rendez();				// rendezes
        if (b[9] != 1 || (b[0] == -8 && b[18] != 10) || (b[0] == 10 && b[18] != -8))
            cout << "Nem kezeli jol a rendezesnel a tenyleges darabszamot!" << endl;
        cout << b[30] << endl;			// ez mar nincs
        cout << "Nem, vagy nem jol figyeli az indexhaterokat!" << endl;
    } catch (exception& e) {
        cout << "Kivetelkezeles: ";
        cout << e.what() << endl;
    }
    cout << vec2 << endl;	// kiírja a 23. 22. 85. 84. 418 indexu elemeket
    // 4 tizedesjegy pontossággal
    return 0;
}

