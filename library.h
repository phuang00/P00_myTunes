#include "linked_list.h"

struct song_node * add_song(struct song_node *input[27], struct song_node);

struct song_node * find_song(struct song_node *input[27], struct song_node);

struct song_node * find_artist(struct song_node *input[27], struct song_node);

struct song_node * print_artists(struct song_node *input[27], struct song_node);

struct song_node * print_songs(struct song_node *input[27], struct song_node);

void print_library(struct song_node *input[27]);

struct song_node * shuffle(struct song_node *input[27], struct song_node);

struct song_node * delete_song(struct song_node *input[27], struct song_node);

struct song_node * clear_library(struct song_node *input[27], struct song_node);
