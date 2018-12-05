#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

const int ERROR = -1;

struct Node
{
  int data;
  Node* next;
  Node* prev;
};


Node* CreateNode(int value)
{
  Node* newn = new Node;
  newn -> data = value;
  newn -> next = NULL;
  newn -> prev = NULL;
  return newn;
}

Node* InsertNodAftr(Node* cur, int value)
{
  Node* newn = new Node;
  newn -> data = value;
  newn -> next = cur -> next;
  newn -> prev = cur;
  cur   -> next = newn;
  return newn;
}

Node* InsertNodBefr(Node* cur, int value)
{
  Node* newn = new Node;
  newn -> data = value;
  newn -> prev = cur -> prev;
  newn -> next = cur;
  cur -> prev -> next = newn;
  return newn;
}

Node* Search_Node (char value , Node* head)
{
  Node* cur =  head;
  for (;;)
  {
    if (cur -> data != value)
    {
      if (cur -> next != NULL)
      cur = cur -> next;
      else
      {
        printf("NE NASHEL\n");
        return NULL;
      }
    }
    else
    {
      return cur;
    }
}
}


int Index_Node (Node* cur, Node* head)
{
    if (cur == head)
    {
      return 1;
    }

    if (cur == NULL)
    {
      return ERROR;
    }
    Node* tmp = cur;
    int counter = 1;
    while (cur -> prev != NULL)
    {
        counter ++;
        cur = (cur -> prev);
    }
    if (counter == 1)
    printf("NE NASHEL\n");
    return counter;
}

void PrintList ( Node* head)
{
    if (head == NULL)
    {
      printf("Empty\n" );
    }
    Node* cur = head;
    while (cur != NULL)
    {
      printf("%d ", cur -> data);
      cur = cur -> next;
    }
    cur = NULL;
    printf("\n");
}

void DeleteNode(int value,  Node* head)
{
  Node* ptr =Search_Node(value  ,head);
  if ( ptr -> next == NULL && ptr -> prev == NULL)
  {
    printf("NO SUCH ELEMENT\n");
  }
  if( ptr -> next == NULL && ptr -> prev != NULL)
  {
    (ptr-> prev) -> next = NULL;
      }
  if( ptr -> next != NULL && ptr -> prev == NULL )
  {
    (ptr-> next)-> prev = NULL;
  }
  if (ptr -> next != NULL && ptr -> prev != NULL)
  {
    (ptr-> prev) -> next = (ptr -> next);
    (ptr-> next)-> prev = (ptr -> prev);
  }
  ptr->data = 0 ;
  ptr = NULL;
}

int DeleteList (Node* head)
{
    if (head == NULL)
    {
        return ERROR;
    }
    Node* tmp = head;
    while (head != NULL)
    {
      head = head -> next;
      tmp -> data = 0;
      tmp -> next = NULL;
      tmp = NULL;
    }
  printf("Empty\n");
}

int main()
{
  int a,b,c;
  scanf("%d %d %d", &a, &b,&c);
  Node* n1 = CreateNode(a);
  Node* n2 = InsertNodAftr(n1, b);
  Node* n3 = InsertNodBefr(n2, c);
  int  q = Index_Node (n3, n1);
  printf("%d\n", q);
  DeleteNode(b, n1);
  Search_Node (b , n1);
  DeleteList (n1);
  Search_Node (a , n1);
  return 0;
}
