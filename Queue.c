#include <stdio.h>
#include <stdlib.h>

struct queue {
    int queue_size;
    int *queue_blocks;
    int front, rear;
} que;

int isfull() {
    return (que.rear == que.queue_size - 1);
}

int isempty() {
    return (que.front > que.rear);
}

void enque() {
    int element;
    printf("Enter the element to enqueue: ");
    scanf("%d", &element);
    if (!isfull()) {
        que.rear++;
        que.queue_blocks[que.rear] = element;
        printf("Element inserted into the queue: %d\n", element);
    } else {
        printf("Queue is full.\n");
    }
}

void deque() {
    if (!isempty()) {
        int deque_element = que.queue_blocks[que.front];
        printf("Dequeued element: %d\n", deque_element);
        que.front++;
    } else {
        printf("Queue is empty.\n");
    }
}

void forward() {
    if (!isempty()) {
        printf("Queue elements (front to rear): ");
        for (int i = que.front; i <= que.rear; i++) {
            printf("%d ", que.queue_blocks[i]);
        }
        printf("\n");
    } else {
        printf("Queue is empty.\n");
    }
}

void backward() {
    if (!isempty()) {
        printf("Queue elements (rear to front): ");
        for (int i = que.rear; i >= que.front; i--) {
            printf("%d ", que.queue_blocks[i]);
        }
        printf("\n");
    } else {
        printf("Queue is empty.\n");
    }
}

int main() {
    int choice;

    printf("Enter the size of the queue: ");
    scanf("%d", &que.queue_size);

    que.queue_blocks = (int *)malloc(sizeof(int) * que.queue_size);
    que.front = 0;
    que.rear = -1;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1) Enqueue\n2) Dequeue\n3) Traverse Forward\n4) Traverse Backward\n5) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enque();
                break;
            case 2:
                deque();
                break;
            case 3:
                forward();
                break;
            case 4:
                backward();
                break;
            case 5:
                free(que.queue_blocks);
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}

