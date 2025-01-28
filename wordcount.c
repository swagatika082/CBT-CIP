#include<stdio.h>
#include<ctype.h>

#define MAX_LINES 100
#define MAX_LENGTH 1000
int count_words(const char *str);
int count_characters(const char *str);

int main(){
    char lines[MAX_LINES][MAX_LENGTH];
    int num_lines = 0;
    printf("enter your text (end with an empty line):\n");
    while (num_lines < MAX_LINES && fgets (lines[num_lines], MAX_LENGTH, stdin) && lines[num_lines][0] != '\n' ) {
        num_lines++;
    }
    int total_words=0;
    int total_characters=0;

    for (int i = 0; i< num_lines; i++) {
        total_words += count_words(lines[i]);
        total_characters += count_characters(lines[i]);
    }

    printf("\ntotal number of lines: %d\n", num_lines);
    printf("total number of words: %d\n", total_words);
    printf("total number of characters: %d\n", total_characters);

    return 0;
}
int count_words(const char *str){
    int count =0;
    int in_word = 0;

    while (*str){
      if (isspace(*str)){
        in_word = 0;
      } else if (!in_word) {
        count++;
        in_word = 1;
      }
      str++;
    }
    return count;
}

int count_characters(const char *str) 
{
  int count = 0;
  while (*str) 
  { 
    count++;
    str++;
  }
  return count;
}