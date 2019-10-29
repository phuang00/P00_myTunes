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
    printf(" %s: %s |", n->i);
    n = n->next;
  }
  printf("\n");
}

struct song_node * song_search(struct song_node *first, char n[100], char a[100]){
  return NULL;
}

struct song_node * first_song(struct song_node *first, char a[100]){
  return NULL;
}

struct song_node * random_song(struct song_node *songs){
  return NULL;
}

struct song_node * remove_song(struct song_node *song){
  return NULL;
}

struct song_node * free_list(struct song_node *songs){
  return NULL;
}
