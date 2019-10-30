#include "library.h"

void add_song(struct song_node *input[27], char n[100], char a[100]){
  int index = find_letter(a);
  insert_order(input[index], n, a);
}

struct song_node * find_song(struct song_node *input[27], char n[100], char a[100]){
  int index = find_letter(a);
  return song_search(input[index], n, a);
}

struct song_node * find_artist(struct song_node *input[27], char a[100]){
  int index = find_letter(a);
  return first_song(input[index], a);
}

void print_letter(struct song_node *input[27], char ltr){
  int index;
  if (ltr >= 97 && ltr <= 122) index = ltr % 97;
  else index = 26;
  print_list(input[index]);
}

void print_songs(struct song_node *input[27], char a[100]){
  struct song_node * start = find_artist(input, a);
  while (strcmp(start->artist, a) == 0){
    print_node(start);
    start = start->next;
  }
}

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

void shuffle(struct song_node *input[27]){
  int i;
  for (i = 0; i < 3; i++){
    int index = rand() % 26;
    struct song_node *song = random_song(input[index]);
    print_node(song);
  }
}

void delete_song(struct song_node *input[27], char n[100], char a[100]){

}

void clear_library(struct song_node *input[27]){
  int i;
  for (i = 0; i < 27; i++){
    free_list(input[i]);
  }
}

int find_letter(char a[100]){
  int letter = a[0];
  if (letter >= 97 && letter <= 122) return letter % 97;
  return 26;
}
