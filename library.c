#include "library.h"

struct song_node * add_song(struct song_node *input[27], char n[100], char a[100]){
  return NULL;
}

struct song_node * find_song(struct song_node *input[27], char n[100], char a[100]){
  return NULL;
}

struct song_node * find_artist(struct song_node *input[27], char a[100]){
  return NULL;
}

void print_letter(struct song_node *input[27], char ltr){

}

void * print_songs(struct song_node *input[27], char a[100]){

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

}

struct song_node * delete_song(struct song_node *input[27], char n[100], char a[100]){
  return NULL;
}

struct song_node * clear_library(struct song_node *input[27]){
  return NULL;
}
