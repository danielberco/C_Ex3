//
// Created by bercod on 05/01/2021.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LINE 256
#define WORD 30

int get_word(char w[]);
int getWord (char words []);
int similar (char *s, char *t, int n);
int get_line(char s[]);
int substring( char * str1, char * str2);
void print_lines(char * str);
void print_similar_words (char *s);


int main (int argc, char *argv[])
{
  char line[LINE];
  char str_search[WORD];
  char ch;
  scanf("%s", str_search);
  scanf("%c", &ch);
  scanf("%c", &ch);
  get_line(line);
  printf("You chose option %c\n", ch);
  if (ch == 'a') {
    //print_lines_containing(str_search, line);
    printf("Printing all lines from the text file containing the word \"%s\":\n", str_search);
  }
  else { //str_option[0] == 'b'
    printf("Printing all words from the text file similar to \"%s\":\n", str_search);
    print_similar_words(str_search);
  }
  return 0;
}
/*
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
''*/

int get_word(char s[]){
  scanf("%s", s);
  return strlen(s);
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

/*
int get_line(char s[]) {
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
*/
int get_line(char s[]){

  fgets(s, LINE , stdin);
  //printf("Read: %s", s);

  s[strcspn( s, "\n" )] = '\0';
  return strlen(s);
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
    while (get_line(text)) {
        if (substring(text,str)) {
            printf("%s\n",text);
        }
    }
}

void print_similar_words (char *s) {
  char text [LINE];
  //int c = scanf("%s",text );
  for (size_t i = 0; i < 50; i++) {
    scanf("%s",text);
    if (similar(text,s,0) || similar(text,s,1)){
      printf("%s\n",text);
    }
  }
}
