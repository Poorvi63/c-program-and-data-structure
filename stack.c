#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

struct node {
    int data;
    struct node* next;
};
struct node* createnode(int data){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
      printf("Memory allocation error\n");
      return NULL;
    }
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void push(struct node** top,int data){
    struct node *newnode=createnode(data);
    if(!newnode){
      printf("Memory allocation\n");
      return;
    }
    newnode->next=*top;
    *top=newnode;
    printf("%d pushed onto to stack\n",data);
}
int pop(struct node **top){
  if(*top == NULL){
    printf("Stack is empty\n");
    return INT_MIN;
  }
  struct node* temp=*top;
  int poppedValue = temp->data;
  *top=temp->next;
  free(temp);
  return poppedValue;
}

int peek(struct node *top){
  if(top==NULL){
    printf("stack is empty\n");
  return INT_MIN;
}
return top->data;
}
int beginning(struct node *top){
  if(top==NULL){
    printf("stack is empty\n");
    return INT_MIN;
  }
  struct node*current=top;
  while(current->next!=NULL){
    current=current->next;
  }
  return current->data;
}
int main(){
  struct node*top = NULL;

   push(&top,10);
   push(&top,20);
   push(&top,30);
   push(&top,40);
   push(&top,50);

  printf("top element is %d\n",peek(top));

  printf("bottom element is %d\n",beginning(top));

  printf("popped element is %d\n",pop(&top));
  printf("popped element is %d\n",pop(&top));

  printf("top elemnt after pop is %d\n",peek(top));

  return 0;
  
}




      
      
    