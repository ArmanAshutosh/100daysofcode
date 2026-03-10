#include <stdio.h>

#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x)
{
    if(front == 0)
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else
        front--;

    deque[front] = x;
}

void push_back(int x)
{
    if(rear == MAX-1)
    {
        printf("Overflow\n");
        return;
    }

    if(front == -1)
        front = rear = 0;
    else
        rear++;

    deque[rear] = x;
}

void pop_front()
{
    if(front == -1)
    {
        printf("Deque Empty\n");
        return;
    }

    printf("%d\n", deque[front]);

    if(front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back()
{
    if(front == -1)
    {
        printf("Deque Empty\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if(front == rear)
        front = rear = -1;
    else
        rear--;
}

void display()
{
    if(front == -1)
    {
        printf("Deque Empty\n");
        return;
    }

    for(int i = front; i <= rear; i++)
        printf("%d ", deque[i]);

    printf("\n");
}

int main()
{
    push_back(10);
    push_back(20);
    push_front(5);
    push_front(2);

    display();

    pop_front();
    pop_back();

    display();

    return 0;
}
