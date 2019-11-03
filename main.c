#include "library.h"

int main() {
  srand(time(NULL));
  struct song_node *songs = NULL;

  printf("LINKED LIST TESTS\n====================================\n\n");

  printf("Testing print_list on empty list:\n");
  print_list(songs);

  printf("====================================\n");
  printf("Testing insert_front\n");
  printf("inserting node: radiohead - paranoid android \n");
  songs = insert_front(songs, "paranoid android", "radiohead");
  printf("inserting node: pearl jam - yellow ledbetter \n");
  songs = insert_front(songs, "yellow ledbetter", "pearl jam");
  printf("inserting node: pearl jam - even flow \n");
  songs = insert_front(songs, "even flow", "pearl jam");
  printf("inserting node: pearl jam - alive \n");
  songs = insert_front(songs, "alive", "pearl jam");
  printf("print_list: \n");
  print_list(songs);

  printf("====================================\n");
  printf("Testing insert_order\n");
  printf("inserting node: radiohead - street spirit (fade out) \n");
  songs = insert_order(songs, "street spirit (fade out)", "radiohead");
  printf("inserting node: pink floyd - time \n");
  songs = insert_order(songs, "time", "pink floyd");
  printf("inserting node: ac/dc - thunderstruck \n");
  songs = insert_order(songs, "thunderstruck", "ac/dc");

  printf("====================================\n");

  printf("Testing print_list:\n");
  print_list(songs);

  printf("====================================\n");

  printf("\nTesting print_node:\n");
  print_node(songs);
  struct song_node *p = NULL;
  printf("\nPrinting empty node:\n");
  print_node(p);

  printf("\n====================================\n");

  printf("\nTesting find_node:\nlooking for [pearl jam: even flow]\n");
  p = find_node(songs, "even flow", "pearl jam");
  if (p == NULL){
    printf(" node not found\n");
  }
  else{
    printf(" node found!");
    print_node(p);
  }
  printf("\nlooking for [pearl jam: daughter]\n");
  p = find_node(songs, "daughter", "pearl jam");
  if (p == NULL){
    printf(" node not found\n");
  }
  else{
    printf(" node found!");
    print_node(p);
  }
  printf("\nlooking for [ac/dc: thunderstruck]\n");
  p = find_node(songs, "thunderstruck", "ac/dc");
  if (p == NULL){
    printf(" node not found\n");
  }
  else{
    printf(" node found!");
    print_node(p);
  }

  printf("\n\n====================================\n");

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
  printf("looking for [ac/dc]\n");
  p = first_song(songs, "ac/dc");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }
  printf("looking for [radiohead]\n");
  p = first_song(songs, "radiohead");
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
  printf("Testing len (helper function)\n");
  printf("length of linked list songs (expected: 7): %d\n", len(songs));
  printf("length of linked list p (expected: 2): %d\n", len(p));

  printf("====================================\n");

  printf("\nTesting random:\n");
  int i;
  for (i = 0; i < 4; i++){
    print_node(random_song(songs));
    printf("\n");
  }
  printf("Testing random on empty list:\n");
  struct song_node *q = NULL;
  print_node(random_song(q));

  printf("\n====================================\n");

  printf("\nTesting remove:\n");
  printf("Removing [pearl jam: alive]\n");
  int length = len(songs);
  songs = remove_song(songs, "alive", "pearl jam");
  if (length == len(songs)){
    printf(" pearl jam - alive not found\n");
  }
  print_list(songs);
  printf("Removing [pearl jam: yellow ledbetter]\n");
  length = len(songs);
  songs = remove_song(songs, "yellow ledbetter", "pearl jam");
  if (length == len(songs)){
    printf(" pearl jam - yellow ledbetter not found\n");
  }
  print_list(songs);
  printf("Removing [pink floyd: alive]\n");
  length = len(songs);
  songs = remove_song(songs, "alive", "pink floyd");
  if (length == len(songs)){
    printf(" pink floyd - alive not found\n");
  }
  print_list(songs);
  printf("Removing [ac/dc: thunderstruck]\n");
  length = len(songs);
  songs = remove_song(songs, "thunderstruck", "ac/dc");
  if (length == len(songs)){
    printf(" ac/dc - thunderstruck not found\n");
  }
  print_list(songs);
  printf("Removing [radiohead: street spirit (fade out)]\n");
  length = len(songs);
  songs = remove_song(songs, "street spirit (fade out)", "radiohead");
  if (length == len(songs)){
    printf(" radiohead - street spirit (fade out)\n");
  }
  print_list(songs);

  printf("====================================\n");

  printf("\nTesting free_list:\n");
  songs = free_list(songs);
  printf("songs after free_list:\n");
  print_list(songs);
  printf("length of linked list songs: %d\n", len(songs));
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
  printf("empty library: \n");
  print_library(table);
  add_song(table, "paranoid android", "radiohead");
  add_song(table, "yellow ledbetter", "pearl jam");
  add_song(table, "even flow", "pearl jam");
  add_song(table, "street spirit (fade out)", "radiohead");
  add_song(table, "alive", "pearl jam");
  add_song(table, "thunderstruck", "ac/dc");
  add_song(table, "time", "pink floyd");
  add_song(table, "peaches", "presidents of the united states of america");
  add_song(table, "some song", "-some-person");
  printf("full library:\n");
  print_library(table);

  printf("====================================\n");

  printf("\nTesting find_index (helper function): \n");
  i = find_index("pearl jam");
  printf("pearl jam belongs to index: %d, which is for letter '%c'\n", i, i + 'a');
  i = find_index("-well_there");
  printf("-well_there belongs to index: %d\n", i);
  i = find_index("adelle");
  printf("adelle belongs to index: %d, which is for letter '%c'\n", i, i + 'a');
  i = find_index("zebra");
  printf("zebra belongs to index: %d, which is for letter' %c'\n", i, i + 'a');



  printf("\n====================================\n");

  printf("\nTesting print_letter:\n");
  printf("p list\n");
  print_letter(table, 'p');
  printf("others list\n");
  print_letter(table, '-');
  printf("b list\n");
  print_letter(table, 'b');

  printf("\n====================================\n");

  printf("\nTesting print_songs: \n");
  printf("All songs by pearl jam: \n");
  print_songs(table, "pearl jam");
  printf("All songs by no-one: \n");
  print_songs(table, "no-one");

  printf("====================================\n");

  printf("\nTesting find:\n");
  printf("looking for [pearl jam: alive]\n");
  p = find_song(table, "alive", "pearl jam");
  if (p == NULL){
    printf(" song not found\n");
  }
  else{
    printf(" song found!");
    print_node(p);
    printf("\n");
  }
  printf("looking for [pearl jam: time]\n");
  p = find_song(table, "time", "pearl jam");
  if (p == NULL){
    printf(" song not found\n");
  }
  else{
    printf(" song found!");
    print_node(p);
    printf("\n");
  }

  printf("\n====================================\n");

  printf("\nTesting find_artist:\n");
  printf("looking for [pearl jam]\n");
  p = find_artist(table, "pearl jam");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }
  printf("looking for [pink floyd]\n");
  p = find_artist(table, "pink floyd");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }
  printf("looking for [shawn mendes]\n");
  p = find_artist(table, "shawn mendes");
  if (p == NULL){
    printf(" artist not found\n");
  }
  else{
    printf(" artist found!");
    print_list(p);
  }


  printf("\n====================================\n");

  printf("\nTesting remove_song:\n");
  printf("removing: [pearl jam: alive]\n");
  delete_song(table, "alive", "pearl jam");
  print_library(table);
  printf("removing: [pearl jam: yellow ledbetter]\n");
  delete_song(table, "yellow ledbetter", "pearl jam");
  print_library(table);
  printf("removing: [shawn mendes: if i cant have you]\n");
  delete_song(table, "if i cant have you", "shawn mendes");
  print_library(table);

  printf("====================================\n");

  printf("\nTesting shuffle:\n");
  shuffle(table);

  printf("====================================\n");

  printf("\nTesting clear_library:\n");
  clear_library(table);
  printf("\nLibrary after clear:\n");
  print_library(table);



  return 0;
}
