#include <stdio.h>
#include <stdlib.h>

#define MAX 5 // Maximum capacity of the stack

int stack[MAX];
int top = -1; // -1 indicates that the stack is initially empty

// Function prototypes
void push();
void pop();
void peek();
void display();

int main() {
    int choice;

    while (1) {
        // Display Menu to the user
        printf("\n--- STACK OPERATIONS MENU ---");
        printf("\n1. Push (Insert Element)");
        printf("\n2. Pop (Delete Element)");
        printf("\n3. Peek (View Top Element)");
        printf("\n4. Display Stack");
        printf("\n5. Exit");
        printf("\nEnter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("\nExiting program. Goodbye!\n");
                exit(0);
            default:
                printf("\nInvalid choice! Please enter a number between 1 and 5.\n");
        }
    }
    return 0;
}

// Function to add an element to the stack
void push() {
    int value;
    
    // Check for Stack Overflow
    if (top == MAX - 1) {
        printf("\nError: Stack Overflow! Cannot push more elements.\n");
    } else {
        printf("Enter the value to push: ");
        scanf("%d", &value);
        top++;             // Move the top pointer up
        stack[top] = value; // Insert the value
        printf("Success: %d pushed onto the stack.\n", value);
    }
}

// Function to remove the top element from the stack
void pop() {
    // Check for Stack Underflow
    if (top == -1) {
        printf("\nError: Stack Underflow! The stack is empty.\n");
    } else {
        printf("Success: %d popped from the stack.\n", stack[top]);
        top--; // Move the top pointer down
    }
}

// Function to view the top element without removing it
void peek() {
    if (top == -1) {
        printf("\nStack is empty. No top element to display.\n");
    } else {
        printf("\nThe top element is: %d\n", stack[top]);
    }
}

// Function to print all elements in the stack
void display() {
    if (top == -1) {
        printf("\nStack is empty.\n");
    } else {
        printf("\nStack elements (from Top to Bottom):\n");
        for (int i = top; i >= 0; i--) {
            printf("| %d |\n", stack[i]);
        }
        printf("-----\n");
    }
}
