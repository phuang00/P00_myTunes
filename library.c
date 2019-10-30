#include "library.h"

void print_library(struct song_node *input[27]){
  int i;
  for (i = 0; i < 27; i++){
    if (input[i] != NULL){
      printf("%c list\n", 65 + i);
      print_list(input[i]);
    }
  }
  printf("\n");
}
