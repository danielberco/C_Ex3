//
// Created by bercod on 05/01/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINE 256
#define WORD 30


int getWord (char words []);
int similar (char *s, char *t, int n);
int getLine(char s[]);
int substring( char * str1, char * str2);
void print_lines(char * str);
void print_similar_words (char *s);




int main() {

    // reads the first line "cat a/b"
    char word[WORD];
    scanf(" %s", word);
    char ch;
    scanf(" %c", &ch);

    if(ch == 'a'){
        print_lines(word);
    }
    if(ch == 'b'){
        print_similar_words(word);
    }
}


int getWord (char words [])
{
    int i=0;
    char c;
    while(!isspace(c=getchar()) && c!=EOF){
        words[i] = c;
        i++;
    }
    words[i] = 0;
    if(c!=EOF)
        return i+1;
    return i;
}



int similar (char *s, char *t, int n)
{
    if(strlen(s) < strlen(t)) return 0;
    while(*s){
        if(*t){
            if(*s != *t) n--;
            else t++;
        }
        else{
            n--;
        }
        s++;
    }
    return n==0;
}

int getLine(char s[]) {
    int i = 0;
    char c;
    while ((c = getchar()) != '\n' && c!= EOF) {
        s[i] = c;
        i++;
    }
    s[i] = 0;
    if (c!=EOF)
        return i+1;
    return i;
}

int substring( char * str1, char * str2)
{
    char *c = str2;
    while (*str1) {
        str2 = c;
        while (*str1 == *str2) {
            str1++;
            str2++;
            if (*str2 == 0 )
                return 1;
        }
        str1++;
    }
    return 0;
}
void print_lines(char * str)
{
    char text [LINE];
    while (getLine(text)) {
        if (substring(text,str)) {
            printf("%s\n",text);
        }
    }
}

void print_similar_words (char *s) {
    char text [LINE];
    while (getWord(text)) {
        if (similar(text,s,0) || similar(text,s,1))
            printf("%s\n",text);
    }
}


