#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/**
 * diagonalDifference - Computes absolute difference between diagonals of square matrix
 * Complexity: Time O(N), Space O(1)
 */
int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    (void)arr_columns;
    int primary_sum = 0;
    int secondary_sum = 0;
    for (int i = 0; i < arr_rows; i++) {
        primary_sum += arr[i][i];
        secondary_sum += arr[i][arr_rows - 1 - i];
    }
    return abs(primary_sum - secondary_sum);
}

int main(void) {
    printf("=== Test: Diagonal Difference ===\n");
    int n = 3;
    int* matrix[3];
    int r0[] = {11, 2, 4};
    int r1[] = {4, 5, 6};
    int r2[] = {10, 8, -12};
    matrix[0] = r0; matrix[1] = r1; matrix[2] = r2;

    int diff = diagonalDifference(n, n, matrix);
    // Primary: 11 + 5 + (-12) = 4
    // Secondary: 4 + 5 + 10 = 19
    // Absolute diff: |4 - 19| = 15
    assert(diff == 15);
    printf("Test Passed: Expected 15, Got %d\n", diff);
    return 0;
}
