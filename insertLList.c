#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL; 

    
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);

        
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    
    printf("Linked list: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    
    int begData;
    printf("Enter data to add at the beginning: ");
    scanf("%d", &begData);
    Node* begNode = (Node*) malloc(sizeof(Node));
    begNode->data = begData;
    begNode->next = head;
    head = begNode;

    
    printf("Linked list after adding at beginning: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    
    int endData;
    printf("Enter data to add at the end: ");
    scanf("%d", &endData);
    Node* endNode = (Node*) malloc(sizeof(Node));
    endNode->data = endData;
    endNode->next = NULL;
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = endNode;

    
    printf("Linked list after adding at end: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    
    int posData;
    int pos;
    printf("Enter data to add at a specific position: ");
    scanf("%d", &posData);
    printf("Enter the position (1-indexed): ");
    scanf("%d", &pos);

    Node* posNode = (Node*) malloc(sizeof(Node));
    posNode->data = posData;
    posNode->next = NULL;

    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
    posNode->next = temp->next;
    temp->next = posNode;

    
    printf("Linked list after adding at position %d: ", pos);
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}
