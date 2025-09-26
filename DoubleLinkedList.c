
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

void insert_begin(struct Node** head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->prev = NULL;
    newNode->next = *head;
    if (*head != NULL)
        (*head)->prev = newNode;
    *head = newNode;
}
void insert_end(struct Node** head, int num) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = num;
    newNode->next = NULL;

    if (*head == NULL) {
        newNode->prev = NULL;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

// Insert after a target node
void insert_after(struct Node* head, int target, int value) {
    struct Node* temp = head;
    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target value %d not found.\n", target);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void insert_before(struct Node** head, int target, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If head node is target
    if (temp->data == target) {
        insert_begin(head, value);
        return;
    }

    while (temp != NULL && temp->data != target)
        temp = temp->next;

    if (temp == NULL) {
        printf("Target value %d not found.\n", target);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    newNode->next = temp;
    newNode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newNode;

    temp->prev = newNode;
}

void delete_begin(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    printf("Deleted value: %d\n", temp->data);

    *head = temp->next;
    if (*head != NULL)
        (*head)->prev = NULL;

    free(temp);
}

void delete_end(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == NULL) {
        printf("Deleted value: %d\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }

    while (temp->next != NULL)
        temp = temp->next;

    printf("Deleted value: %d\n", temp->data);

    temp->prev->next = NULL;
    free(temp);
}
void delete_spec(struct Node** head, int value) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    printf("Deleted value: %d\n", temp->data);

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        *head = temp->next; 

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

// Traverse forward
void travel_forward(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}
void travel_back(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, input, target;

    while (1) {
        printf("\n1.insert at begin\n2.insert at end\n3.insert after the target element\n4.insert before the target\n5.delete beg\n6.delete end\n7.delete specific\n8.travel forward list\n9.travel back\n10.exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at beginning: ");
                scanf("%d", &input);
                insert_begin(&head, input);
                break;

            case 2:
                printf("Enter element to insert at end: ");
                scanf("%d", &input);
                insert_end(&head, input);
                break;

            case 3:
                printf("Enter target element after which to insert: ");
                scanf("%d", &target);
                printf("Enter element to insert: ");
                scanf("%d", &input);
                insert_after(head, target, input);
                break;

            case 4:
                printf("Enter target element before which to insert: ");
                scanf("%d", &target);
                printf("Enter element to insert: ");
                scanf("%d", &input);
                insert_before(&head, target, input);
                break;

            case 5:
                delete_begin(&head);
                break;

            case 6:
                delete_end(&head);
                break;

            case 7:
                printf("Enter element to delete: ");
                scanf("%d", &input);
                delete_spec(&head, input);
                break;

            case 8:
                printf("Traversing forward: ");
                travel_forward(head);
                break;

            case 9:
                printf("Traversing backward: ");
                travel_back(head);
                break;

            case 10:
                printf("Exiting...\n");
                while (head != NULL)
                    delete_begin(&head);
                exit(0);

            default:
                printf("Invalid choice. Try again.\n");
                break;
        }
    }
    return 0;

}

