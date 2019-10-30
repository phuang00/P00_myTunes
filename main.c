#include "library.h"

int main() {
  srand(time(NULL));
  struct song_node *songs = NULL;
  songs = insert_front(songs, "paranoid android", "radiohead");
  songs = insert_front(songs, "yellow ledbetter", "pearl jam");
  songs = insert_front(songs, "even flow", "pearl jam");
  songs = insert_order(songs, "street spirit (fade out)", "radiohead");
  songs = insert_front(songs, "alive", "pearl jam");
  songs = insert_front(songs, "thunderstruck", "ac/dc");
  songs = insert_order(songs, "time", "pink floyd");

  printf("LINKED LIST TESTS\n====================================\n\n");

  printf("Testing print_list:\n");
  print_list(songs);

  printf("====================================\n");

  printf("\nTesting print_node:\n");
  print_node(songs);

  printf("\n====================================\n");

  printf("\nTesting song_search:\nlooking for [pearl jam: even flow]\n");
  struct song_node *p = song_search(songs, "even flow", "pearl jam");
  if (p == NULL){
    printf(" node not found\n");
  }
  else{
    printf(" node found!");
    print_node(p);
  }
  printf("\nlooking for [pearl jam: daughter]\n");
  p = song_search(songs, "even flow", "daughter");
  if (p == NULL){
    printf(" node not found\n");
  }
  else{
    printf(" node found!");
    print_node(p);
  }

  printf("====================================\n");

  printf("\nTesting first_song:\nlooking for [pink floyd]\n");
  p = first_song(songs, "pink floyd");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }
  printf("looking for [pearl jam]\n");
  p = first_song(songs, "pearl jam");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }
  printf("looking for [presidents of the united states of america]\n");
  p = first_song(songs, "presidents of the united states of america");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }

  printf("====================================\n");

  printf("\nTesting songcmp (helper function):\n");
  printf("Comparing [pearl jam: even flow] to [pearl jam: even flow]\n");
  p = NULL;
  p = insert_front(p, "even flow", "pearl jam");
  printf("%d\n", songcmp(p, "even flow", "pearl jam"));
  printf("Comparing [pearl jam: even flow] to [pearl jam: alive]\n");
  printf("%d\n", songcmp(p, "alive", "pearl jam"));
  printf("Comparing [pearl jam: alive] to [pearl jam: even flow]\n");
  p = insert_front(p, "alive", "pearl jam");
  printf("%d\n", songcmp(p, "even flow", "pearl jam"));
  printf("Comparing [pearl jam: even flow] to [pink floyd: time]\n");
  printf("%d\n", songcmp(p, "time", "pink floyd"));

  printf("====================================\n");

  printf("\nTesting random:\n");
  int i;
  for (i = 0; i < 4; i++){
    print_node(random_song(songs));
    printf("\n");
  }

  printf("====================================\n");

  printf("\nTesting remove:\n");
  printf("Removing [pearl jam: alive]\n");
  p = insert_front(p, "alive", "pearl jam");
  int length = len(songs);
  songs = remove_song(songs, p);
  if (length == len(songs)){
    printf(" pearl jam - alive not found\n");
  }
  print_list(songs);
  printf("Removing [pearl jam: yellow ledbetter]\n");
  p = insert_front(p, "yellow ledbetter", "pearl jam");
  length = len(songs);
  songs = remove_song(songs, p);
  if (length == len(songs)){
    printf(" pearl jam - yellow ledbetter not found\n");
  }
  print_list(songs);
  printf("Removing [pink floyd: alive]\n");
  p = insert_front(p, "alive", "pink floyd");
  length = len(songs);
  songs = remove_song(songs, p);
  if (length == len(songs)){
    printf(" pink floyd - alive not found\n");
  }
  print_list(songs);

  printf("====================================\n");

  printf("\nTesting free_list:\n");
  songs = free_list(songs);
  printf("songs after free_list:\n");
  print_list(songs);
  p = free_list(p);
  printf("p after free_list:\n");
  print_list(p);

  printf("====================================\n");

  printf("\nMUSIC LIBRARY TESTS\n");

  printf("\n====================================\n");

  struct song_node * table[27];
  for (i = 0; i < 27; i++){
    table[i] = NULL;
  }

  printf("\nTesting print_library\n");
  print_library(table);

  printf("====================================\n");

  printf("\nTesting print_letter:\n");
  printf("p list\n");
  print_letter(table, 'p');

  printf("====================================\n");

  printf("\nTesting find:\n");
  printf("looking for [pearl jam: alive]\n");
  p = find_song(table, "alive", "pearl jam");
  if (p == NULL){
    printf("song not found\n");
  }
  else{
    printf("song found!");
    print_node(p);
  }

  return 0;
}
