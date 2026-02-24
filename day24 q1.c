#include <stdio.h>
#include <stdlib.h>

// Define structure
struct Node {
    int data;
    struct Node* next;
};

int main() {
    int n, key, i;
    struct Node *head = NULL, *temp = NULL, *newNode = NULL;
    
    scanf("%d", &n);

    // Create linked list
    for(i = 0; i < n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newNode->data);
        newNode->next = NULL;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
        } else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    scanf("%d", &key);

    // Delete first occurrence
    struct Node *current = head, *prev = NULL;

    // If head contains key
    if(current != NULL && current->data == key) {
        head = current->next;
        free(current);
    } else {
        while(current != NULL && current->data != key) {
            prev = current;
            current = current->next;
        }

        if(current != NULL) {
            prev->next = current->next;
            free(current);
        }
    }

    // Print updated list
    temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
