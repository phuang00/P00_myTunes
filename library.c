#include "library.h"

void add_song(struct song_node *input[27], char n[100], char a[100]){
  int index = find_index(a);
  input[index] = insert_order(input[index], n, a);
}

struct song_node * find_song(struct song_node *input[27], char n[100], char a[100]){
  int index = find_index(a);
  return song_search(input[index], n, a);
}

struct song_node * find_artist(struct song_node *input[27], char a[100]){
  int index = find_index(a);
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
  while (start != NULL && strcmp(start->artist, a) == 0){
    print_node(start);
    printf("|");
    start = start->next;
  }
  printf("\n");
}

void print_library(struct song_node *input[27]){
  int i;
  for (i = 0; i < 27; i++){
    if (input[i] != NULL){
      if (i != 26){
        printf("%c list\n", 97 + i);
      }
      else{
        printf("others list\n");
      }
      print_list(input[i]);
    }
  }
  printf("\n");
}

void shuffle(struct song_node *input[27]){
  int i;
  for (i = 0; i < 3; i++){
    int index = rand() % 26;
    if (len(input[index]) > 0){
      struct song_node *song = random_song(input[index]);
      print_node(song);
      printf("\n");
    }
    else{
      i--;
    }
  }
}

void delete_song(struct song_node *input[27], char n[100], char a[100]){
  int index = find_index(a);
  input[index] = remove_song(input[index], n, a);
}

void clear_library(struct song_node *input[27]){
  int i;
  for (i = 0; i < 27; i++){
    input[i] = free_list(input[i]);
  }
}

int find_index(char a[100]){
  int letter = a[0];
  if (letter >= 97 && letter <= 122) return letter % 97;
  return 26;
}
