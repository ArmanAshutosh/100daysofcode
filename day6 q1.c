#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // If array is empty, nothing to print
    if (n == 0) {
        return 0;
    }

    // Print the first element
    printf("%d ", arr[0]);

    // Print only when current element is different from previous
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
