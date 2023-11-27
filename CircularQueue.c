#include <stdio.h>
#include <stdlib.h>

#define size 3

int front = -1;
int rear = -1;
int arr[size];

void deque() {
    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else if (front == rear) {
        printf("%d ", arr[front]);
        arr[front] = 0;
        front = -1;
        rear = -1;
    } else {
        printf("%d ", arr[front]);
        arr[front] = 0;
        front = (front + 1) % size;
    }
}

void enque(int temp) {
    if ((rear + 1) % size == front) {
        printf("Queue is full\n");
    } else if (front == -1 && rear == -1) {
        front = 0;
        rear = 0;
        arr[front] = temp;
    } else {
        rear = (rear + 1) % size;
        arr[rear] = temp;
    }
}

void display() {
    int i = front;

    if (front == -1 && rear == -1) {
        printf("Queue is empty\n");
    } else {
        do {
            printf("%d ", arr[i]);
            i = (i + 1) % size;
        } while (i != (rear + 1) % size);
        printf("\n");
    }
}

int main() {
    int option, in = 0;

    while (1) {
        printf("\nQueue Menu\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("Enter the option : ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                printf("Enter the no. : ");
                scanf("%d", &in);
                enque(in);
                break;
            case 2:
                deque();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option\n");
        }
    }

    return 0;
}
