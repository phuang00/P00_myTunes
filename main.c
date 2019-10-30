#include "linked_list.h"

int main() {
  srand(time(NULL));
  struct song_node *songs = NULL;
  songs = insert_front(songs, "street spirit (fade out)", "radiohead");
  songs = insert_front(songs, "paranoid android", "radiohead");

  printf("LINKED LIST TESTS\n====================================\n\n");
  printf("Testing print_list:\n");
  print_list(songs);
  printf("Testing random_song:\n");
  int i;
  for (i = 0; i < 10; i++){
    print_list(random_song(songs));
  }
  return 0;
}
