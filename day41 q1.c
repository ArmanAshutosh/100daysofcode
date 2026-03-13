#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

// Enqueue function
void enqueue(int x)
{
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = NULL;

    if(rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

// Dequeue function
void dequeue()
{
    if(front == NULL)
    {
        printf("-1\n");
        return;
    }

    struct node* temp = front;
    printf("%d\n", front->data);

    front = front->next;

    if(front == NULL)
        rear = NULL;

    free(temp);
}

int main()
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char op[10];
        scanf("%s", op);

        if(op[0] == 'e') // enqueue
        {
            int x;
            scanf("%d", &x);
            enqueue(x);
        }
        else if(op[0] == 'd') // dequeue
        {
            dequeue();
        }
    }

    return 0;
}
