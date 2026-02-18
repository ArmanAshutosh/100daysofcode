#include <stdio.h>

int main() {
    int n, k;

    // Input size
    scanf("%d", &n);

    int arr[n];

    // Input elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input k
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Print rotated array
    for (int i = n - k; i < n; i++) {
        printf("%d ", arr[i]);
    }

    for (int i = 0; i < n - k; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
