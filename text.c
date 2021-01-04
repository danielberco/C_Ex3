#include <stdio.h>
#include <string.h>
#define LINESIZE 256
#define WORDSIZE 30

int get_line(char s[]){

  fgets(s, LINESIZE , stdin);
  //printf("Read: %s", s);

  s[strcspn( s, "\n" )] = '\0';
  return strlen(s);
}

int substring(char *str1, char *str2){
  return 0;
}

int similar(char *s, char *t, int n){
  return 0;
}

void print_lines_containing(char *str, char line[]){
  get_line(line);

  while(1){
    char* str_currentword = strtok(line, " ");
    int b = 0;

    while(str_currentword != NULL){
      if (str_currentword == str) {
        b = 1;
      }
      str_currentword = strtok(line, " ");
    }


    if (b == 1) {
      printf("%s\n", line);
    }
    get_line(line);
    if (line == !EOF) {
      break;
    }
  }

}

void print_similar_words(char *str, char line[]){


}

int main (int argc, char *argv[])
{
  char line[LINESIZE]; get_line(line);

  char* str_search = strtok(line, " ");
  char* str_option = strtok(NULL, " ");
  get_line(line);

  if (str_option[0] == 'a') {
    print_lines_containing(str_search, line);
  } else {
    //str_option[0] == 'b'
    print_similar_words(str_search, line);
  }
  return 0;
}

/*
#include <stdio.h>
#define BUFFERSIZE 250


int main (int argc, char *argv[])
{
    char buffer[BUFFERSIZE];
    fgets(buffer, BUFFERSIZE , stdin);
    printf("Read: %s", buffer);
    fgets(buffer, BUFFERSIZE , stdin);
    fgets(buffer, BUFFERSIZE , stdin);
    printf("Read: %s", buffer);
    return 0;


  //int arr[5] = {99, 78, -1, 42, 12};
  //int n = sizeof(arr)/sizeof(int);

  //print_array(&arr[0], n);

  //insertion_sort(&arr[0], n);

  //print_array(&arr[0], n);

}
*/
