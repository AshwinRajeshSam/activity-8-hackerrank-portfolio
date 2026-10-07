#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    (void)a_count; (void)b_count;
    *result_count = 2;
    int* score = (int*)calloc(2, sizeof(int));
    for (int i = 0; i < 3; i++) {
        if (a[i] > b[i]) score[0]++;
        else if (a[i] < b[i]) score[1]++;
    }
    return score;
}

int main(void) {
    printf("=== Test: Compare the Triplets ===\n");
    int a[] = {5, 6, 7};
    int b[] = {3, 6, 10};
    int count = 0;
    int* score = compareTriplets(3, a, 3, b, &count);
    assert(score[0] == 1 && score[1] == 1);
    printf("Test Passed: Expected [1, 1], Got [%d, %d]\n", score[0], score[1]);
    free(score);
    return 0;
}
