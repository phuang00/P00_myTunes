#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};

struct song_node * insert_front(struct song_node *first, char n[100], char a[100]);

struct song_node * insert_order(struct song_node *first, char n[100], char a[100]);

void print_list(struct song_node *n);

struct song_node * find_node(struct song_node *first, char n[100], char a[100]);

struct song_node * first_song(struct song_node *first, char a[100]);

struct song_node * random_song(struct song_node *songs);

struct song_node * remove_song(struct song_node *first, char n[100], char a[100]);

struct song_node * free_list(struct song_node *songs);

void print_node(struct song_node *song);

int songcmp(struct song_node *a, char b_name[100], char b_artist[100]);

int len(struct song_node *song);
