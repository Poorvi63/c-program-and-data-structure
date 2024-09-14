#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TABLE_SIZE 10


struct node{
    int key;
    int value;
    struct node *next;
};


struct node* hashtrouble[TABLE_SIZE];


int hashfunction(int key){
  return key% TABLE_SIZE;
}

void insert(int key, int value){
  int hashindex = hashfunction(key);
  struct node *newnode = (struct node*)malloc(sizeof(struct node));
  newnode->key = key;
  newnode->value = value;
  newnode->next = NULL;

  if(hashtrouble[hashindex] == NULL){
    hashtrouble[hashindex] = newnode;
  }else{
    newnode->next = hashtrouble[hashindex];
    hashtrouble[hashindex] = newnode;
  }
}

int search(int key){
  int hashindex = hashfunction(key);
  struct node* currentnode = hashtrouble[hashindex];

  while(currentnode != NULL){
    if(currentnode->key == key){
      return currentnode->value;
    }
    currentnode = currentnode->next;
  }
  return -1;
}

void diplay(){
  for(int i = 0; i < TABLE_SIZE; i++){
    struct node* currentnode = hashtrouble[i];
    printf("Index %d: ", i);
    while(currentnode != NULL){
      printf("(%d, %d) -> ", currentnode->key, currentnode->value);
      currentnode = currentnode->next;
    }
    printf("NULL\n");
  }
}
int main(){
  for(int i = 0; i < TABLE_SIZE; i++){
    hashtrouble[i] = NULL;
  }
  insert(1, 10);
  insert(11, 20);
  insert(21, 30);
  insert(2, 40);
  insert(12, 50);
  display();

  int value = search(21);
  if(value != -1){
    printf("Value for key 21: %d\n", value);
  }else{
    printf("Key 21 not found\n");
  }
  return 0;
}
