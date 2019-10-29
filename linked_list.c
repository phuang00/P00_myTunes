#include "linked_list.h"

struct song_node * insert_front(struct song_node *first, char n[100], char a[100]){
  struct song_node *node = malloc(sizeof(struct song_node));
  strcpy(node->name, n);
  strcpy(node->arist, a);
  node->next = first;
  return node;
}

struct song_node * insert_order(struct song_node *first, char n[100], char a[100]){
  return NULL;
}

void print_list(struct song_node *n){
  while (n != NULL){
    printf(" %s: %s |", n->arist, n->name);
    n = n->next;
  }
  printf("\n");
}

struct song_node * song_search(struct song_node *first, char n[100], char a[100]){
  while (first != NULL){
    if (strcmp(first->name, n) == 0 && strcmp(first->artist, a) == 0){
      return first;
    }
    first = first->next;
  }
  return NULL;
}

struct song_node * first_song(struct song_node *first, char a[100]){
  while (first != NULL){
    if (strcmp(first->artist, a) == 0){
      return first;
    }
    first = first->next;
  }
  return NULL;
}

struct song_node * random_song(struct song_node *songs){
  return NULL;
}

struct song_node * remove_song(struct song_node *first, struct song_node *song){
  struct song_node *front = first;
  struct song_node *prev;
  while (song != NULL){
    if (strcmp(song->name, front->name) == 0 && strcmp(song->artist, front->artist) == 0){
      if (front == first){
        first = front->next;
      }
      else{
        prev->next = front->next;
      }
      free(front);
      return first;
    }
    prev = front;
    front = front->next;
  }
  return first;
}

struct song_node * free_list(struct song_node *songs){
  struct node *temp = songs;
  while (songs != NULL){
    temp = songs->next;
    free(songs);
    songs = temp;
  }
  return temp;
}
