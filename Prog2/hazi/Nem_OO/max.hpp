#ifndef _MAX_HPP
#define _MAX_HPP
/**
 * file max.hpp (latin2 kodolasu fajl)
 *
 * A C++ nem OO bõvítéseinek gyakorlásához.
 *
 *
 * FELADATOK:
 *  2. Valósítson meg EBBEN a fájlban, a Sajat névtéren belül egy olyan sablont, ami
 *     alaptípusok esetén a paraméterként kapott érték közül a nagyobbat adja.
 *  3. Specializálja a sablont a nem_oo.h állományban deklarált Komplex típusra
 *     úgy hogy a nagyobb abszolút értékû Komplex számot adja vissza!
 *
 * Ügyeljen a helyes névtér használatra!
 */

namespace sajat {

	template <typename T>
		T max( T a, T b)
		{
			T res;
			res = (a>=b) ? a : b;
			return (res);
		}
	template <>
		Komplex max<Komplex>(Komplex a, Komplex b){
			Komplex res;
			res = (absKomplex(a) >= absKomplex(b)) ? a : b;
			return res;
		}
}


#endif

