/* 
 * File:   main.c
 * Author: Bernd Robertz (eurobertics@outlook.com)
 *
 * Created on 26. Oktober 2015, 10:25
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 */

#include <stdio.h> // Just for test output (printf)
#include <stdlib.h>
#include <string.h>

char *dec2bin(const char *input) {
    int size = strlen(input);
    char *binstorage = malloc(sizeof(char) * size * 8 + 1);
    int pos = 0;
    for(int i = 0; i < size; i++) {
	char c = (int)input[i];
	for(int ii = 7; ii >= 0; ii--) {
	    int b = ((1 << ii) & c) != 0 ? 1 : 0;
	    binstorage[pos] = '0' + b;
	    pos++;
	}
    }
    binstorage[pos] = '\0';
    return binstorage;
}

char *bin2dec(const char *bindata) {
    int size = strlen(bindata), dec = 0, i = 0;
    char *retstring = malloc(sizeof(char) * (size / 8));
    for(int c = 0; c < size; c++) {
	dec = dec << 1;
	if(bindata[c] == '1') {
	    dec += 1;
	}
	i++;
	if(i == 8) {
	    retstring[(c / 8)] = dec;
	    dec = 0;
	    i = 0;
	}
    }
    retstring[(size / 8)] = '\0';
    return retstring;
}

int main(int argc, char** argv) {
    char *testbin = dec2bin("Hello World.");
    printf("%s\n", testbin);
    char *testascii = bin2dec(testbin);
    printf("%s", testascii);
    return 0;
}
