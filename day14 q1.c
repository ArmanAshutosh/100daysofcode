#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int matrix[n][n];
    int isIdentity = 1;  // Assume it is identity

    // Input matrix
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Check identity condition
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {

            if(i == j) {
                // Diagonal elements must be 1
                if(matrix[i][j] != 1) {
                    isIdentity = 0;
                    break;
                }
            } else {
                // Non-diagonal elements must be 0
                if(matrix[i][j] != 0) {
                    isIdentity = 0;
                    break;
                }
            }
        }
        if(isIdentity == 0)
            break;
    }

    if(isIdentity)
        printf("Identity Matrix");
    else
        printf("Not an Identity Matrix");

    return 0;
}
