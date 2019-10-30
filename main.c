#include "linked_list.h"

int main() {
  srand(time(NULL));
  struct song_node *songs = NULL;
  songs = insert_order(songs, "street spirit (fade out)", "radiohead");
  songs = insert_front(songs, "paranoid android", "radiohead");
  songs = insert_front(songs, "time", "pink floyd");
  songs = insert_front(songs, "yellow ledbetter", "pearl jam");
  songs = insert_front(songs, "even flow", "pearl jam");
  songs = insert_front(songs, "alive", "pearl jam");
  songs = insert_front(songs, "thunderstruck", "ac/dc");

  printf("LINKED LIST TESTS\n====================================\n\n");
  printf("Testing print_list:\n");
  print_list(songs);
  printf("Testing random_song:\n");
  int i;
  for (i = 0; i < 10; i++){
    print_list(random_song(songs));
  }
  printf("Testing print_list:\n");
  songs = insert_order(songs, "hello", "world");
  songs = insert_order(songs, "hejjo", "world");
  songs = insert_order(songs, "hejjo", "world");
  songs = insert_order(songs, "stuy", "arista");
  songs = insert_order(songs, "stuy", "arist");
  songs = insert_order(songs, "stuy", "Arist");
  songs = insert_order(songs, "middleton", "khris");
  songs = insert_order(songs, "niddleton", "khris");
  songs = insert_order(songs, "williamson", "zion");
  print_list(songs);
  return 0;
}
