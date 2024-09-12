
#include<stdio.h>  
#include<stdlib.h>  
void beginsert(int);  
struct node  
{  
    int data;  
    struct node *next;  
};  
struct node *head;  
void printList(struct node* node);
void main ()  
{  
    int choice,item;  
    do   
    {  
        printf("\nEnter the item which you want to insert?\n");  
        scanf("%d",&item);  
        beginsert(item);  
        printf("\nPress 0 to insert more ?\n");  
        scanf("%d",&choice);  
    }while(choice == 0);  

    printList(head);
}  
void beginsert(int item)  
    {  
        struct node *ptr = (struct node *)malloc(sizeof(struct node *));  
        if(ptr == NULL)  
        {  
            printf("\nOVERFLOW\n");  
        }  
        else  
        {  
            ptr->data = item;  
            ptr->next = head;  
            head = ptr;  
            printf("\nNode inserted\n");  
        }  
          
    }

void printList(struct node* node) {
  while (node != NULL) {
  printf("%d ", node->data);
  node = node->next;
  }
}