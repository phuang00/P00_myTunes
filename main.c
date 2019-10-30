#include "linked_list.h"

int main() {
  struct song_node *songs = NULL;
  songs = insert_front(songs, "street spirit (fade out)", "radiohead");
  songs = insert_front(songs, "paranoid android", "radiohead");
  songs = insert_front(songs, "time", "pink floyd");
  songs = insert_front(songs, "yellow ledbetter", "pearl jam");
  songs = insert_front(songs, "even flow", "pearl jam");
  songs = insert_front(songs, "alive", "pearl jam");
  songs = insert_front(songs, "thunderstruck", "ac/dc");

  printf("LINKED LIST TESTS\n====================================\n\n");
  printf("Testing print_list:\n");
  print_list(songs);
  return 0;
}
