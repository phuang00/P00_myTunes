#include "linked_list.h"

int main() {
  struct song_node *songs = NULL;
  songs = insert_front(songs, "street spirit (fade out)", "radiohead");
  songs = insert_front(songs, "paranoid android", "radiohead");

  printf("LINKED LIST TESTS\n====================================\n\n");
  printf("Testing print_list:\n");
  print_list(songs);
  return 0;
}
