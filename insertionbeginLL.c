
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* head = NULL; // initialize an empty linked list

    // Take user input for the number of nodes
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    // Take user input for the data of each node
    for (int i = 0; i < n; i++) {
        int data;
        printf("Enter data for node %d: ", i+1);
        scanf("%d", &data);

        // Create a new node with the user input data
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;

        // Add the new node to the end of the linked list
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

    // Print the linked list to verify
    printf("Linked list: ");
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Add a node at the beginning of the linked list
    int begData;
    printf("Enter data to add at the beginning: ");
    scanf("%d", &begData);
    Node* begNode = (Node*) malloc(sizeof(Node));
    begNode->data = begData;
    begNode->next = head;
    head = begNode;

    // Print the updated linked list
    printf("Linked list after adding at beginning: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Add a node at the end of the linked list
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

    // Print the updated linked list
    printf("Linked list after adding at end: ");
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    // Add a node at a specific position in the linked list
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

    // Print the updated linked list
    printf("Linked list after adding at position %d: ", pos);
    temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");

    return 0;
}