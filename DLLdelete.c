#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}


void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void deleteFirstNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    free(temp);
    printf("First node deleted.\n");
}

void deleteInnerNode(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = *head;
    int count = 1;
    
    while (temp != NULL && count < position) {
        temp = temp->next;
        count++;
    }
    
    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }

    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }

    free(temp);
    printf("Node at position %d deleted.\n", position);
}

void deleteLastNode(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;  
    }
    
    free(temp);
    printf("Last node deleted.\n");
}

void display(struct Node* head) {
    struct Node* temp = head;
    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add Node\n");
        printf("2. Delete First Node\n");
        printf("3. Delete Inner Node\n");
        printf("4. Delete Last Node\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                append(&head, data);
                break;
            case 2:
                deleteFirstNode(&head);
                break;
            case 3:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteInnerNode(&head, position);
                break;
            case 4:
                deleteLastNode(&head);
                break;
            case 5:
                display(head);
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
