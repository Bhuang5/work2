#include <stdio.h>
#include <stdlib.h>

struct node {int i; struct node *next; };

int print_list(struct node *start){  
  //Base case 1 for empty linked list
  if(start == 0 ){
    printf("{}\n");
    return 0;
  }
  
  //Base case 2
  if(start->next == 0){
    printf("%d \n", start->i);
    return 0;
  }

  //Recursive call
  printf("%d, ", start->i);
  return print_list(start->next);
}

struct node* insert_front(struct node *front, int x){
  //The "constructor" for the new front k
  struct node *k = (struct node *)calloc(1, sizeof(struct node *));
  
  //Insert
  k->next = front;
  k->i = x;
  return k;
}

struct node* free_list(struct node *front){
  //Place holder
  struct node *p;  
  while(front != NULL){
    p = front->next; //Move p forward
    free(front); //Free the node before p
    front = p; //Move front from just freed node to p
  }
  return front;

  /*
  Broken recursive
  
  //Base case
  if(front == NULL){
    return front;
  }
  
  //Recursively goes through linkedlist until the end
  if(free_list(front->next) == NULL){
    free(front); //frees each node
  }
  return free_list(front->next);
  */
}

int main(){
  struct node *a = 0;
  int length = 0;
  printf("Node a: \n");
  print_list(a); 

  printf("insert_front(1) \n");
  a = insert_front(a, 1);
  print_list(a);
 
  printf("insert_front(3) \n");
  a = insert_front(a, 3);
  print_list(a); 

  printf("insert_front(5) \n");
  a = insert_front(a, 5);
  print_list(a);  

  printf("insert_front(10) \n");
  a = insert_front(a, 10);
  print_list(a);  
 
  printf("\n");

  printf("Testing free_list(a)\n");  
  struct node *b = free_list(a);
  print_list(b);

  //  printf("node *a = 0\n");
  //  a = 0;
  //  print_list(a);
  
  return 0;
}
