/**
 * Implement the following function with 1e-4 precision!
 *
 * f(X) = X/104.65, if X > 34,
 * f(X) = 0.408*X^4 - 0.816*X^3 + 52.25*X^2 + 2*X - 34, if X <= 34
 *
 * Write a program that reads real numbers from standard input until end of file,
 * and calculates the function value (using the above function)
 * for each of them!
 * The results should be printed on the standard output line by line, and
 * always immediately after the real number is read from stdin!
 */

#include <iostream>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;

double f( double x){
	if(x <= 34) {
		return ((((0.408*x)-0.816)*x+52.25)*x+2)*x-34;
	} else {
		return x/104.65;
	}
}

int main(int argc, char *argv[]){

	char myid[]   = "Nagy Dominik,1MI,15,L4M <nd1531@hszk.bme.hu> M8CFQC\n";
	char mytask[] = "Feladat = 2 English\n";
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid); 
	printf(mytask);

	double x = 0;

	while(cin >> x){
		cout << std::fixed << std::setprecision(5) << f(x) << endl;
	}

	return 0;
}
