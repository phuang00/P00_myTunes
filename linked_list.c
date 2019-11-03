#include "linked_list.h"

struct song_node * insert_front(struct song_node *first, char n[100], char a[100]){
  struct song_node *node = malloc(sizeof(struct song_node));
  strcpy(node->name, n);
  strcpy(node->artist, a);
  node->next = first;
  return node;
}

struct song_node * insert_order(struct song_node *first, char n[100], char a[100]){
  //printf("Inserting [%s : %s] into list\n", a, n);
  if (first == NULL){
    return insert_front(first, n, a);
  }
  struct song_node *temp = first; //temp storage of node
  struct song_node *prev = NULL; //stores previous node
  while (temp && songcmp(temp, n, a) <= 0){ //while node exists, alphabetical by artist
    prev = temp;
    temp = temp->next;
  }
  if (prev == NULL){ //insert at front of list
    return insert_front(temp, n, a);
  }
  prev->next = insert_front(temp, n, a);
  return first;
}

void print_list(struct song_node *n){
  while (n != NULL){
    print_node(n);
    printf("|");
    n = n->next;
  }
  printf("\n");
}

struct song_node * find_node(struct song_node *first, char n[100], char a[100]){
  while (first != NULL){
    if (songcmp(first, n, a) == 0){
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
  int length = len(songs);
  if (length > 0    ){
    int index = rand() % length;
    for (; index > 0; index--){
      songs = songs->next;
    }
  }
  return songs;
}

struct song_node * remove_song(struct song_node *first, char n[100], char a[100]){
  struct song_node *front = first;
  struct song_node *prev;
  while (front != NULL){
    if (songcmp(front, n, a) == 0){
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
  struct song_node *temp = songs;
  while (songs != NULL){
    temp = songs->next;
    free(songs);
    songs = temp;
  }
  return temp;
}

void print_node(struct song_node *song){
  if (song != NULL){
    printf(" %s: %s ", song->artist, song->name);
  }
}

int songcmp(struct song_node *a, char b_name[100], char b_artist[100]){
  int ans = strcmp(a->artist, b_artist);
  if (ans != 0){
    return ans;
  }
  return strcmp(a->name, b_name);
}

int len(struct song_node *song){
  int i = 0;
  while (song != NULL){
    i++;
    song = song->next;
  }
  return i;
}
