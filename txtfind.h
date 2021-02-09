//
//  txtfind.h
//  Ex3-C
//
//  Created by Itai Lash on 23/12/2020.
//

#ifndef txtfind_h
#define txtfind_h

#include <stdio.h>
#include <string.h>

int getLine(char s[]);
int substring( char * str1, char * str2);
int getWord(char w[]);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

#endif /* txtfind_h */
