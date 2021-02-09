//#include "txtfind.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int getLine(char s[]);
int substring( char * str1, char * str2);
int getWord(char w[]);
int similar (char *s, char *t, int n);
void print_lines(char * str);
void print_similar_words(char * str);

int main() {
    char str [WORD];
    getWord(str);
    char option[1];
    getWord(option);
    if(option[0] == 'a'){
        print_lines(str);
    }
    if(option[0] == 'b'){
        print_similar_words(str);
    }
    return 0;
}

void print_lines(char * str){
    char line[LINE] = "";
    char c;
    while((c = getc(stdin)) != EOF){
        if(c != '\n'){
            line[0] = c;
            getLine(line);
            if(substring(line,str)){
                printf("%s", line);
            }
        }
    }
}

void print_similar_words(char * str){
    char word[WORD];
    while(getWord(word) != 0){
        if(similar(word,str,0) || similar(word,str,1)){
            printf("%s", word);
            printf("\n");
            
        }
    }
}

int getLine(char s[]){
    int i = 1;
    int counter = 0;
    char c;
    while((c = getc(stdin)) != '\n'){
        s[i] = c;
        i++;
        counter++;
    }
    s[i] = '\n';
    s[i+1] = '\0';
    return counter;
}

int getWord(char w[]){
    int i = 0;
    int counter = 0;
    char c = getc(stdin);
    if(c == EOF){
        return 0;
    }
    while(c != '\n' && c != '\t' && c != ' ' && c != EOF){
        w[i] = c;
        i++;
        counter++;
        c = getc(stdin);
    }
    if(w[i-1] == '\r'){
        i-=1;
    }
    if(c != EOF){
       w[i] = '\0';
    }
    return counter;
}

int substring( char * str1, char * str2){
    if(strlen(str1) < strlen(str2)){
        return 0;
    }
    int idx1 = 0 ,idx2 = 0;
    int counter = 0;
    while(idx1<strlen(str1) && idx2<strlen(str2)){
        if(str1[idx1] == str2[idx2]){
            counter++;
            idx1++;
            idx2++;
        }
        else{
            idx1++;
            idx2 = 0;
            counter = 0;
        }
    }
    if(counter == strlen(str2)){
        return 1;
    }
    return 0;
}

int similar (char *s, char *t, int n){
    if(strlen(s) != strlen(t)+n){
        return 0;
    }
    int idxS = 0 ,idxT = 0;
    int counter = 0;
    while(idxS<strlen(s) && idxT<strlen(t)){
        if(t[idxT] != s[idxS]){
            counter++;
            idxS++;
            if(counter > n){
                return 0;
            }
        }
        else{
            idxS++;
            idxT++;
        }
    }
    return 1;
}


