#include <stdio.h>
#include <string.h>

#define MAX 1000

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up
void heapifyUp(int index)
{
    while(index > 0)
    {
        int parent = (index - 1) / 2;

        if(heap[parent] > heap[index])
        {
            swap(&heap[parent], &heap[index]);
            index = parent;
        }
        else
            break;
    }
}

// Heapify Down
void heapifyDown(int index)
{
    while(1)
    {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int smallest = index;

        if(left < size && heap[left] < heap[smallest])
            smallest = left;

        if(right < size && heap[right] < heap[smallest])
            smallest = right;

        if(smallest != index)
        {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        }
        else
            break;
    }
}

// Insert Operation
void insert(int value)
{
    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Extract Minimum
void extractMin()
{
    if(size == 0)
    {
        printf("-1\n");
        return;
    }

    printf("%d\n", heap[0]);

    heap[0] = heap[size - 1];
    size--;
    heapifyDown(0);
}

// Peek Operation
void peek()
{
    if(size == 0)
        printf("-1\n");
    else
        printf("%d\n", heap[0]);
}

int main()
{
    int n, value;
    char operation[20];

    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        scanf("%s", operation);

        if(strcmp(operation, "insert") == 0)
        {
            scanf("%d", &value);
            insert(value);
        }
        else if(strcmp(operation, "extractMin") == 0)
        {
            extractMin();
        }
        else if(strcmp(operation, "peek") == 0)
        {
            peek();
        }
    }

    return 0;
}
