/**
 * \mainpage Operátorok átdefiniálása
 *
 * \par Feladat:
 * Készítsünk olyan osztályt, ami bemutatja a tanult átdefiniálható operátorokat!<br>
 * Nem fontos, hogy értelmes mûveletek legyenek, helyette inkább próbáljuk kiíratni
 * magát a mûveletet, és figyeljük meg a konstruktorok, destruktorok hívási mechanizmusát!
 *
 * \par Megvalósítás:
 * - %A példányok egy int tagváltozót tartalmaznak. %A mûveleteket azonban nem hajtjuk végre, így a változót sem frissítjük.
 * - Minden átdefiniálható operátort definiáltunk. %A konstruktorokat és néhány tagfüggvényt elkészítettünk elõre.
 * - %A megvalósított tagfüggvények kiírják a mûveletben résztvevõ objektumok címét és magát a mûveletet.
 *   Az operátorok többsége azonban csak egy soremelést ír ki a standard kimenetre.
 * - %A fõprogramban az összes C++-ban használható operátort egy-egy utasítással meghívjuk egy _ nevû makró segítségével, melynek
 * funkciója az, hogy magát az utasítást is kiírja a szabványos kimenetre, majd kitesz egy kommentjelet.
 * - Így, ha az adott operátor valamit kiír, az a kommentjel után jelenik meg.
 * Pl:
 \code
    a + b   // IDE írhat a + operátor
    a++;    // IDE pedig a ++ operátor
 \endcode
 *
 * \par Demonstrációs cél:
 *  - konstruktorok, destruktorok szerepe
 *  - operátorok átdefiniálása, paraméterezése, mûködése
 *
 * \par Feladatok:
 *  -# \b Töltse le, fordítsa, majd futtassa a félkész <a href="../operatorok_h.cpp"> operatorok_h.cpp</a> programot!
 *  -# \b Értse meg a mûködést, \b magyarázza meg a kiírásokat!
 *  -# Definiálja a \b NEW makrót és figyelje meg a \em new, \em delete operatorok mûködését!
 *  -# \b Tegyen töréspontot a \em new operátorra, majd fordítsa le és futtassa az alkalmazást Debug módban!
 *  -# %A töréspont elérésekor \b nyisson egy memória ablakot, amelyben a \em mem1 terület látszik (Debug->Debuging Windows->Memory dump)!
 *     \b Tipp: Érdemes a \em Memory \em dump ablakot behúzni a \em Manager ablak alá.
 *  -# Most \b tegyen töréspontot a konstruktorra, majd engedje továbbfutni az alkalmazást!
 *  -# \b Értse meg, hogy mi történik a \em new, \em delete, \em new[] és \em delete[] operátorok hívásakor!
 *     %A megjegyzések segítenek a megértésben
 *  -# \b Figyelje meg, hogy a konstruktor/destruktor mindenképpen meghívódik!
 *  -# \b Figyelje meg, hogy a \em delete programozott törzse mikor hajtódik végre!
 *  -# \b Valósítson meg néhány további operátort pl:
 \code
    void operator++(int)  { ///< %A++ (post)
        cout << "  " << this << "++" << endl;
    }
 \endcode
 *  -# %A \b main függvény minden \em tanult operátort meghív. Olyat is, ami \b nem \b definiálható át!
 *  -# %A \em felsorolás és a \em csoportosítás az \b operátorok \b prioritásának felel meg.
 *  -# Az \b ELKESZULT makróval szabályozható, hogy mely utasításokat hajtsa végre. Az összes végrehajtható, mert a meg nem
 *     valósított operátorok egy üres sort írnak ki. Így az \b ELKESZULT makró csupán a kiírások számának csökkentésére szolgál.
 *  -# \b Keresse meg azokat az operátorokat, melyek \b nem definiálhatók át, és értse meg, hogy mi történik hatásukra!
 *  -# \b Módosítsa az összeadás, a kivonás és az értékadás operátorokat úgy, hogy azok láncolhatók legyenek!
 *  -# Egy-egy példán \b vizsgálja meg a mûködésüket (pl: c = a + b - b;)!
 *  -# \b Valósítson meg néhány további mûvelet (+, -, +=, ++) úgy, hogy azok az elvárt hatással legyenek az osztályban tárolt egészre.
 *
 * \par Szorgalmi feladat:
 * Módosítsa az osztályt úgy, hogy
 *  -# Minden konstruktorhíváskor írja ki, hogy az adott példány hanyadik létezõ példány!
 *  -# %A másoló konstruktor írja ki, hogy hanyadik példányt másolta le! (javaslat: statikus tag)
 *  -# \b Csak \b bekötött biztonsági övvel: Definiálja az EXTRA makrót és értse meg a mûködést!
 *
 * \par Jó munkát!
 */

#include <iostream>
#include <iomanip>
#include <cstring>

#define ELKESZULT 0

using std::cout;
using std::endl;

char mem1[1024];			// ezt a területet adja vissza a new
char mem2[1024];			// ezt a területet adja vissza a new[]


/// Trükkös makrók, nem kell megértenie
#define _(x) cout << std::setiosflags(std::ios::left) << std::setw(20) << #x << " //";  x
#define __(x,y) cout << #x << " , " << std::setiosflags(std::ios::left) << std::setw(16) << #y << " //";  x, y
#define E cout << endl;


/**
 * Állatorvosi ló osztály.
 * Az összes átdefiniálható operatort megvalósítja.
 * %A mûveletek bemutatatása a cél. Nem cél az értelmes megvalósítás.
 * Az operatorok visszatérési értéke void. Természetesen ez sokszor nem áll összhangban szokásos mûködéssel.
 * Szükség esetén ezt változtassa meg!
 * %A kétoperandusú operátorok jobb oldali operandusát mindig konstans referenciaként adjuk át,
 * bár ez is megváltoztatható lenne.
 */
struct A {
    int  adat;              ///< adattag.  Az elõre elkészített kódban nincs funkciója
    enum { piros, zold };	///< csak azért, hogy a :: meghívható legyen egy példára

    /// Konstruktor.
    /// Kiírja, hogy mit hoz létre
    A(int i = -1)     {
        adat = i;
        cout << "  " << this << " letrejott" << endl;
    }

    /// Másoló konstruktor.
    /// Kiírja, hogy mit, hova másol
    A(const A& a)         {
        cout << "  " << this << " masolat errol: " << &a << endl;
    }

    /// Értékadó operátor.
    /// Kiírja, hogy kinek mit ad értékül
    void operator=(const A& a) {
        cout << "  " << this << " ertet kap innen: " << &a << endl;
    }

    /// Desruktor
    ~A()                  {
        cout << "  " << this << " megszunt" << endl;
    }

    /// Kétoperandusú * operátor (szorzás)
    void operator*(const A& a) {
        cout << "  " << this << " * " << &a << endl;
    }

    /// Egyoperandusú + operátor
    void operator+()      {
        cout << "  +" << this << endl;
    }

    /// operátor ->
    /// Leginkább okos pointernek használható.
    /// Ez az egyik kakukktojás, mert nehezen használható másra.
    /// Érvényes címet kell, hogy visszaadjon a struktúrára, és nem az adattagra.
    /// Az adattag nem jelenik meg a szintaxisban, mert a -> egyoperandusú operátor.
    A    *operator->()    {
        cout << "  " << this << " visszadta ezt: " << this << endl;
        return this;
    }

#ifdef NEW
    /// operátor new
    /// A másik kakukktojás, mert nem nagyon használható másra, ráadásul statikus tagfüggvény.
    /// Csak void* lehet és kötelezõ visszaadni egy pointert, amivel mindenképpen meghívja
    /// az osztály konstruktorát. Így a visszaadott címnek és a hozzá tartozó területnek érvényesnek kell lennie.
    static void *operator new(unsigned int size) {
        cout << "  new size: " << size << " return: " << (void*)mem1 << endl;
        return mem1;
    }

#ifdef EXTRA
    /// placement new
    /// Nagyon kakukktojás, és nagyon EXTRA
    /// A paraméterként kapott címen meghívja a konstruktort. Egyéb extra paramétereket is kaphat (itt pl. az s).
    static void *operator new(unsigned int size, void* p, const char *s) {
        cout << "  placement new size: " << size << " s: " << s << " return: " << p << endl;
        return p;
    }
#endif // EXTRA

    /// operátor new[]
    /// Újabb kakukktojás, mert nem nagyon használható másra, ráadásul ez is statikus tagfüggvény.
    /// Csak void* lehet és kötelezõ visszaadni egy pointert.
    /// A visszaadott címnek és a hozzá tartozó területnek érvényesnek kell lennie, mert a területre beírja
    /// az tömb méretét, majd meghívja minden elemre a konstruktort, hogy minden elem létrejöjjön.
    static void *operator new[](unsigned int size) {
        cout << "  new[] size: " << size << " return: " << (void*)mem2 << endl;
        return mem2;
    }

    /// operátor delete
    /// Újabb kakukktojás, mert nem nagyon használható másra (ez is statikus).
    /// A paramétere csak void* lehet. A destruktort meghívja a pointerrel.
    /// Csak ezután futtatja le a programozott törzset
    static void operator delete(void *p) {

    }

    /// operátor delete[]
    /// Újabb kakukktojás, mert nem nagyon használható másra (ez is statikus).
    /// A paramétere csak void* lehet. Meghívja minden elemre a destruktort, hogy minden elem megszûnjön.
    /// A darabszámot egyébként kapott memóriacímrõl veszi!
    /// Csak ezután futtatja le a programozott törzset
    static void operator delete[](void *p) {

    }
#endif // NEW

    /// Vesszõ operátor
    void operator,(const A& a)  {
        cout << "  " << this << " , " << &a << endl;
    }

    void operator++(int)        { E } ///< A++	(post)
    void operator++()           { E } ///< ++A	(pre)
    void operator--(int)        { E } ///< A--	(post)
    void operator--()           { E } ///< --A	(pre)
    operator int()              { E return 0;} ///< (int) cast
    void operator()()           { E } ///< függvényhívás
    void operator+(const A& a)  { E } ///< Kétoperandusú + operátor
    void operator-(A& a)        { E } ///< Kétoperandusú - operátor
    void operator-()            { E } ///< Egyoperandusú - operátor
    void operator[](int i)      { E } ///< indexelés
    void operator*()            { E } ///< Egyoperandusú * operátor (indirekció)
    void operator/(const A& a)  { E } ///< / operátor
    void operator%(const A& a)  { E } ///< % operátor
    void operator^(const A& a)  { E } ///< ^ operátor
    void operator&(const A& a)  { E } ///< Kétoperandusú & (bitenkénti és)
    void operator&()            { E } ///< Egyoperandusú & (címképzés)
    void operator|(const A& a)  { E } ///< | operátor
    void operator~()            { E } ///< ~ operátor
    void operator!()            { E } ///< ! operátor
    void operator<<(const A& a) { E } ///< << operátor
    void operator>>(const A& a) { E } ///< >> operátor
    void operator<(const A& a)  { E } ///< < operátor
    void operator>(const A& a)  { E } ///< > operátor
    void operator<=(const A& a) { E } ///< <= operátor
    void operator>=(const A& a) { E } ///< >= operátor
    void operator==(const A& a) { E } ///< == operátor
    void operator!=(const A& a) { E } ///< == operátor
    void operator+=(const A& a) { E } ///< += operátor
    void operator-=(const A& a) { E } ///< -= operátor
    void operator*=(const A& a) { E } ///< *= operátor
    void operator/=(const A& a) { E } ///< /= operátor
    void operator%=(const A& a) { E } ///< %= operátor
    void operator^=(const A& a) { E } ///< ^= operátor
    void operator&=(const A& a) { E } ///< &= operátor
    void operator|=(const A& a) { E } ///< |= operátor
    void operator<<=(const A& a){ E } ///< <<= operátor
    void operator>>=(const A& a){ E } ///< >>= operátor
    void operator&&(const A& a) { E } ///< && operátor
    void operator||(const A& a) { E } ///< || operátor
};

/**
 * Minden operator meghívásra kerül. Azok is, amelyek nem definiálhatók át.
 * Melyek ezek?
 * Az _ makró az utasítás kiírását végzi.
 */
int main() {
_(  A a(1);                 )
_(  A b(2);                 )
_(  A c = b;                )
//-----------------------
_(  a++;                    )
_(  b--;                    )
_(  a[13];                  )
_(  a();                    )
_(  a.adat = 5;             ) E
_(  a->adat = 5;            )
_(  A::piros;               ) E
//-----------------------
#if ELKESZULT > 1
_(  sizeof(b);              ) E
_(  ++b;                    )
_(  --a;                    )
_(  &a;                     )
_(  *a;                     )
_(  +a;                     )
_(  -a;                     )
_(  ~a;                     )
_(  !a;                     )
_(  (int)a;                 )
#endif // ELKESZULT > 1
#ifdef NEW
_(  A *p = new A;           )
_(  A *pt = new A[2];       )
_(  delete p;               )
#ifdef EXTRA
_(  new(mem1, "Barbatrukk") A(5);   )
/// nem szüntetjük meg az objektumot, az már nagyon ronda. Ez is :)
#endif
_(  delete[] pt;            )

#endif
//-----------------------
_(  a * b;                  )
#if ELKESZULT > 2
_(  a / b;                  )
_(  a % b;                  )
//-----------------------
_(  a + b;                  )
_(  a - b;                  )
//-----------------------
_(  a << b;                 )
_(  a >> b;                 )
//-----------------------
_(  a < b;                  )
_(  a <= b;                 )
_(  a > b;                  )
_(  a >= b;                 )
//-----------------------
_(  a == b;                 )
_(  a != b;                 )
//-----------------------
_(  a & b;                  )
//-----------------------
_(  a ^ b;                  )
//-----------------------
_(  a | b;                  )
//-----------------------
_(  a && b;                 )
//-----------------------
_(  a || b;                 )
//-----------------------
_(  a ? a : b;              ) E
//-----------------------
#endif // ELKESZULT > 2
_(  a = b;                  )
#if ELKESZULT > 3
_(  a *= b;                 )
_(  a /= b;                 )
_(  a %= b;                 )
_(  a += b;                 )
_(  a -= b;                 )
_(  a &= b;                 )
_(  a ^= b;                 )
_(  a |= b;                 )
_(  a <<= b;                )
_(  a >>= b;                )
#endif // ELKESZULT > 3
//-----------------------
__(  a , b;                 )
//-----------------------
    return 0;
}
