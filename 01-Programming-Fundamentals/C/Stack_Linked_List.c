#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct Node {
    int data;
    struct Node* next;
};

// Global top pointer initialized to NULL (Empty Stack)
struct Node* top = NULL;

// Function declarations
void push(int value);
void pop();
void peek();
void display();

int main() {
    int choice, value;

    printf("=== Stack Operations Using Linked List ===\n");
    
    while(1) {
        printf("\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch(choice) {
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
                exit(0);
            default:
                printf("Invalid choice! Please choose a valid option.\n");
        }
    }
    return 0;
}

// 1. PUSH: Inserts an element at the top of the stack
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Check if heap memory allocation failed
    if (newNode == NULL) {
        printf("Stack Overflow! Unable to allocate memory.\n");
        return;
    }
    
    newNode->data = value;      // Assign data
    newNode->next = top;       // Link new node to the previous top node
    top = newNode;             // Make the new node the current top
    printf("%d successfully pushed onto the stack.\n", value);
}

// 2. POP: Removes the top element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow! The stack is already empty.\n");
        return;
    }
    
    struct Node* temp = top;   // Temporary pointer to hold current top
    printf("Popped element: %d\n", top->data);
    top = top->next;           // Move top to the next node
    free(temp);                // Deallocate memory of the old top node
}

// 3. PEEK: Displays the topmost element without removing it
void peek() {
    if (top == NULL) {
        printf("Stack is empty.\n");
    } else {
        printf("Top element is: %d\n", top->data);
    }
}

// 4. DISPLAY: Prints all elements in the stack from top to bottom
void display() {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack elements (Top -> Bottom):\n");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
