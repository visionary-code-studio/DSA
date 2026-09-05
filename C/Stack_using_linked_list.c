#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer initialized to NULL (indicates empty stack)
struct Node* top = NULL;

// Function to push an element onto the stack
void push(int value) {
    // Dynamically allocate memory for a new node
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if heap memory is full (Stack Overflow)
    if (newNode == NULL) {
        printf("Stack Overflow! Cannot allocate memory.\n");
        return;
    }
    
    newNode->data = value;
    newNode->next = top; // Point the new node to the current top node
    top = newNode;       // Make the new node the top of the stack
    printf("%d successfully pushed onto the stack.\n", value);
}

// Function to pop an element from the stack
void pop() {
    // Check if the stack is empty (Stack Underflow)
    if (top == NULL) {
        printf("Stack Underflow! The stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;     // Temporarily store the top node
    printf("Popped element: %d\n", top->data);
    
    top = top->next;             // Move the top pointer to the next node
    free(temp);                  // Free the memory of the popped node
}

// Function to view the topmost element without removing it
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// Function to display all elements in the stack
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function handling dynamic user input
int main() {
    int choice, value;
    
    printf("--- Stack Implementation Using Linked List ---\n");
    
    while (1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        
        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                scanf("%d", &value);
                push(value);
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
                printf("Exiting program...\n");
                
                // Free remaining memory before exiting to prevent memory leaks
                while (top != NULL) {
                    struct Node* temp = top;
                    top = top->next;
                    free(temp);
                }
                exit(0);
            default:
                printf("Invalid choice! Please select a valid option.\n");
        }
    }
    return 0;
}
