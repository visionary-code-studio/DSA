#include <stdio.h>
#include <stdlib.h>

#define MAX 5  // Maximum capacity of the stack

int stack[MAX];
int top = -1;

// Check if the stack is full
int isFull() {
    return top == MAX - 1;
}

// Check if the stack is empty
int isEmpty() {
    return top == -1;
}

// Add an element to the top of the stack
void push(int value) {
    if (isFull()) {
        printf("Stack Overflow! Cannot push %d.\n", value);
    } else {
        top++;
        stack[top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Remove and return the top element of the stack
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! Nothing to pop.\n");
        return -1; 
    } else {
        int poppedValue = stack[top];
        top--;
        return poppedValue;
    }
}

// View the top element without removing it
void peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", stack[top]);
    }
}

// Display all elements in the stack
void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements (top to bottom): ");
        for (int i = top; i >= 0; i--) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                value = pop();
                if (value != -1) {
                    printf("Popped element: %d\n", value);
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
