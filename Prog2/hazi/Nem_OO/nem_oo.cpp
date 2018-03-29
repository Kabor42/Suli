#include <cstring>
#include <cctype>
#include "nem_oo.h"

/**
 * \file nem_oo_teszt.cpp
 * (Latin-2 kodolasu fajl. Allitsa at a kodolast,
 *  ha a tovabbi kommentek nem olvashatok helyesen!)
 *
 * FELADATOK:
 *  1. Ebben a fájlban valósítsa meg a nem_oo.h állományban deklarált függvényeket
 *     (atoi(), strcat(), unique()!
 *
 * Ügyeljen a helyes névtér használatra!
 */

namespace sajat{
	int atoi(const char *p, int base){
		int ret = 0, tmp = 0;
		while(!isspace(*p) && *p != '\0'){
			tmp = *p - '0';

			if (tmp >= base){
				const char* exception = "M8CFQC";
				throw exception;
			}

			ret = ret*base + tmp;
			p++;
		}

		return ret;
	}



	char *strcat(const char *p2, const char *p3){
		size_t len = strlen(p2) + strlen(p3) + 1;
		char *ret = new char[len];
		const char *p_cp;
		char *p_ret;
		p_ret = ret;
		p_cp = p2;
		while(*p_cp != '\0'){
			*(p_ret++) = *(p_cp++);
		}
		p_cp = p3;
		while(*p_cp != '\0'){
			*(p_ret++) = *(p_cp++);
		}
		*p_ret = '\0';

		return ret;
	}


	char *unique(char *first, char *last){
		if (first == last)
			return last;
        char *ptr, *res;
        ptr = first;
        res = first;
        while (ptr++ != last){
            if ( *ptr != *res && ptr != res){
                *(++res)  = *ptr;
            }
        }
        *res = '\0';
        return res;
	}
}
