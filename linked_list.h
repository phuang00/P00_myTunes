#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *first, char n[100], char a[100]);

struct song_node * insert_order(struct song_node *first, char n[100], char a[100]);

void print_list(struct song_node *n);

struct song_node * song_search(struct song_node *first, char n[100], char a[100]);

struct song_node * first_song(struct song_node *first, char a[100]);

struct song_node * random_song(struct song_node *songs);

struct song_node * remove_song(struct song_node *first, struct song_node *song);

struct song_node * free_list(struct song_node *songs);
