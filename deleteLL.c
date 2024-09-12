#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int data;
    struct Node* next;
} Node;


void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


Node* deleteFromBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from beginning.\n");
        return head;
    }
    Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}


Node* deleteFromEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from end.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}


Node* deleteFromPosition(Node* head, int pos) {
    if (head == NULL) {
        printf("List is empty. Cannot delete from position.\n");
        return head;
    }
    if (pos == 1) {
        return deleteFromBeginning(head);
    }
    Node* temp = head;
    for (int i = 1; i < pos - 1; i++) {
        if (temp->next == NULL) {
            printf("Position out of range. Cannot delete from position.\n");
            return head;
        }
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Position out of range. Cannot delete from position.\n");
        return head;
    }
    Node* nodeToDelete = temp->next;
    temp->next = temp->next->next;
    free(nodeToDelete);
    return head;
}

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
    printList(head);

    
    printf("Deleting from beginning...\n");
    head = deleteFromBeginning(head);
    printf("Linked list after deleting from beginning: ");
    printList(head);

    
    printf("Deleting from end...\n");
    head = deleteFromEnd(head);
    printf("Linked list after deleting from end: ");
    printList(head);

    
    int pos;
    printf("Enter the position (1-indexed) to delete from: ");
    scanf("%d", &pos);
    printf("Deleting from position %d...\n", pos);
    head = deleteFromPosition(head, pos);
    printf("Linked list after deleting from position %d: ", pos);
    printList(head);

    return 0;
}