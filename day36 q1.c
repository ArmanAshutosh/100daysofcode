#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = 0, rear = -1, count = 0;

void enqueue(int x, int n) {
    if (count == n)
        return;
    rear = (rear + 1) % n;
    queue[rear] = x;
    count++;
}

int dequeue(int n) {
    if (count == 0)
        return -1;
    int val = queue[front];
    front = (front + 1) % n;
    count--;
    return val;
}

int main() {
    int n, m, i, x;

    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for(i = 0; i < m; i++) {
        int temp = dequeue(n);
        enqueue(temp, n);
    }

    for(i = 0; i < count; i++) {
        printf("%d ", queue[(front + i) % n]);
    }

    return 0;
}
