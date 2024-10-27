#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a linked list with an initial node
void createList(struct Node** head, int data) {
    *head = createNode(data);
}

// Function to display the linked list
void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to insert a node before a given node value
void insertBefore(struct Node** head, int target, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        printf("List is empty!\n");
        free(newNode);
        return;
    }
    if ((*head)->data == target) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data != target) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node with value %d not found.\n", target);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to insert a node after a given node value
void insertAfter(struct Node* head, int target, int data) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
    } else {
        struct Node* newNode = createNode(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }
    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }
    struct Node* temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Function to delete a node after a given node value
void deleteAfter(struct Node* head, int target) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("Node with value %d not found or no node after it.\n", target);
    } else {
        struct Node* toDelete = temp->next;
        temp->next = temp->next->next;
        free(toDelete);
    }
}

// Function to delete the entire list
void deleteEntireList(struct Node** head) {
    struct Node* temp;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    printf("Entire list deleted.\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, target;

    do {
        printf("\nMenu:\n");
        printf("1. Create a single linked list\n");
        printf("2. Display the list\n");
        printf("3. Insert at the beginning\n");
        printf("4. Insert at the end\n");
        printf("5. Insert before a given node\n");
        printf("6. Insert after a given node\n");
        printf("7. Delete from the beginning\n");
        printf("8. Delete from the end\n");
        printf("9. Delete after a given node\n");
        printf("10. Delete the entire list\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (head != NULL) {
                    printf("List already created.\n");
                } else {
                    printf("Enter data for the initial node: ");
                    scanf("%d", &data);
                    createList(&head, data);
                }
                break;

            case 2:
                printf("Linked List: ");
                displayList(head);
                break;

            case 3:
                printf("Enter data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;

            case 4:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;

            case 5:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert before %d: ", target);
                scanf("%d", &data);
                insertBefore(&head, target, data);
                break;

            case 6:
                printf("Enter target node value: ");
                scanf("%d", &target);
                printf("Enter data to insert after %d: ", target);
                scanf("%d", &data);
                insertAfter(head, target, data);
                break;

            case 7:
                deleteFromBeginning(&head);
                break;

            case 8:
                deleteFromEnd(&head);
                break;

            case 9:
                printf("Enter target node value after which to delete: ");
                scanf("%d", &target);
                deleteAfter(head, target);
                break;

            case 10:
                deleteEntireList(&head);
                head = NULL;
                break;

            case 11:
                deleteEntireList(&head);
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 11);

    return 0;
}
