//
// Created by bercod on 05/01/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINE 256
#define WORD 30

int similar (char *s, char *t, int n);
int substring( char * str1, char * str2);
void print_lines_containing(char *s);
void print_similar_words (char *s);


int main (int argc, char *argv[])
{
  char line[LINE];
  char str_search[WORD];
  char ch;

  scanf("%s", str_search);
  scanf("%c", &ch); scanf("%c", &ch);
  fgets(line, LINE, stdin);

  printf("You chose option %c\n", ch);

  if (ch == 'a') {
    printf("Printing all lines from the text file containing the word \"%s\":\n", str_search);
    print_lines_containing(str_search);
  }
  else { //str_option[0] == 'b'
    printf("Printing all words from the text file similar to \"%s\":\n", str_search);
    print_similar_words(str_search);
  }
  return 0;
}

int get_word(char s[]){
  scanf("%s", s);
  return strlen(s);
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

void print_lines_containing(char *s)
{
  char t[LINE];
  while(fgets(t, LINE, stdin))
  {
    if(substring(t, s))
    {
      printf("%s",t);
    }
  }
}

void print_similar_words (char *s) {
  char text [LINE];
  int c = 1;
  while (c == 1) {
    c = scanf("%s",text);
    if (similar(text,s,0) || similar(text,s,1)){
      printf("%s\n",text);
    }
  }
}
