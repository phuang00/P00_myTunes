#include "linked_list.h"

void add_song(struct song_node *input[27], char n[100], char a[100]);

struct song_node * find_song(struct song_node *input[27], char n[100], char a[100]);

struct song_node * find_artist(struct song_node *input[27], char a[100]);

void print_letter(struct song_node *input[27], char ltr);

void print_songs(struct song_node *input[27], char a[100]);

void print_library(struct song_node *input[27]);

void shuffle(struct song_node *input[27]);

void delete_song(struct song_node *input[27], char n[100], char a[100]);

void clear_library(struct song_node *input[27]);

int find_letter(char a[100]);
