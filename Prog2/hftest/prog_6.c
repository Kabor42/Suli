// Copyright 2018 Kabor

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/**
 * Problem 6 for Nagy Dominik (M8CFQC):
 * Write a C program that counts the number of lines read from
 * standard input, and also counts the lines that match the following
 * (see problem 4) regular expression:
 *
 * ^[^#]_?(0)*[0-9]*W6.+[A-Z]*.*qqriq(A|b)
 *
 * The program should print the result as two octal numbers!
 * The two numbers should be separated by /, the line should
 * be ended with end of line, e.g.:
 * 123/71
 *
 * The regular expression above should be interpreted by you,
 * no separate interpereter program is to be made! E.g. For the
 * [A-Z]+ expression you have to create a state machine that accepts
 * line containing only capital letters.
 */

bool matchRegex(const char* str, const size_t len) {
	size_t pos = 0;                         /** String pointer position */
	bool retval = true;                     /** Default return value */
	char *pStr = NULL;                      /** String pointer for "qqriq" substring */
	pStr = strstr( str, "qqriq");           /** Check if string contains 'qqriq'   */
	if ( NULL == pStr)                      /** without is meaningless to continue */
		return false;
	int qqriqpos = (int) (pStr - str);      /** Get 'qqriq' position */

	if('#' == str[pos++])                   /**   ^[^#]  if starts with '#' then its bad */
		return false;
	if('_' == str[pos]) {                   /**   _?     */
		if(pos <= len) {										/**   (0)*  */
			pos++; 
		} else {
			return false;
		}								
	}
	while('0' == str[pos]) {
		if(pos <= len) {
			pos++;
		} else {
			return false; 
		}
	}
	while(isdigit((int)str[pos])) {          /**   [0-9]*   */
		if(pos <= len) {
			pos++;
		} else { 
			return false;
		}
	}
	if('W' != str[pos++])                   /**    W6    */
		return false;
	if('6' != str[pos++])
		return false;
	while(!isupper((int)str[pos])) {         /**    .*    while not UPPERcase */
		if(pos <= len) {
			pos++;
		} else {
			return false;
		}
	}
	while(isupper((int)str[pos])) {           /**     [A-Z]*  */
		if(pos <= len) {
			pos++;
		} else { 
			return false;
		}
	}
	while((pos < qqriqpos)){                /**     .*  while not 'qqriq' */
		if(pos <= len) { 
			pos++;
		} else { 
			return false;
		}
	}
	pos += 5;                               /**     'qqriq' */
	if( 'A' != str[pos] && 'b' != str[pos]) /*      (A|b)   */
		return false;

	/** Experimenting */

	pos++;
	if('\n' != str[pos++])
		return false;
	if('\0' != str[pos])
		return false;

	//printf("\t%c\t[%4ld<>%4ld]\n", str[pos], pos, len);

	/** ######################################################### */

	return retval;
}


int main() {

	const unsigned int buffSize = 8192;     /** BUFFER size */

	/** Neccessary for hftest */
	char myid[]   = "Nagy Dominik,1MI,15,L4M <nd1531@hszk.bme.hu> M8CFQC\n";
	char mytask[] = "Feladat = 6 English\n";
	setbuf(stdout, NULL);        // Kikapcsolja a bufferelest
	printf(myid);
	printf(mytask);
	/** --------------------------------------------------------------  */

	char *line = (char*) malloc(buffSize + 1);  /** allocate memory for line buffer */
	size_t len = 0;                             /** length of read line     */

	int ord = 0, reg = 0;                       /** ordinary line, regex line */

	while((fgets( line, buffSize, stdin)) != NULL){     /** read line to buffer from stdin, while not error or EOF */
		fprintf( stderr, "%s", line);
		len = strlen(line);                             /** get line length */
		if(matchRegex(line,len))                        /** match with REGEX */
			reg++;
		ord++;                                          /** count every line */
	}

	free(line);                                 /** Free line buffer */

	printf("%o/%o\n", ord, reg);

	return 0;
}
