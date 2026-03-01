#include <stdio.h>
#include <stdlib.h>

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

// Function to rotate the linked list
struct Node* rotateRight(struct Node* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    struct Node* temp = head;
    int length = 1;

    // Find length and last node
    while (temp->next != NULL) {
        temp = temp->next;
        length++;
    }

    // Make list circular
    temp->next = head;

    k = k % length;   // If k > length
    int steps = length - k;

    // Move to (length - k)th node
    temp = head;
    for (int i = 1; i < steps; i++) {
        temp = temp->next;
    }

    // New head
    head = temp->next;
    temp->next = NULL;

    return head;
}

// Function to print linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main() {
    int n, data, k;

    scanf("%d", &n);

    struct Node *head = NULL, *tail = NULL;

    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        struct Node* newNode = createNode(data);

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    scanf("%d", &k);

    head = rotateRight(head, k);

    printList(head);

    return 0;
}
