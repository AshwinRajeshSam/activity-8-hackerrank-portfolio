#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int* matchingStrings(int stringList_count, char** stringList, int queries_count, char** queries, int* result_count) {
    *result_count = queries_count;
    int* results = (int*)calloc(queries_count, sizeof(int));
    for (int q = 0; q < queries_count; q++) {
        for (int s = 0; s < stringList_count; s++) {
            if (strcmp(queries[q], stringList[s]) == 0) {
                results[q]++;
            }
        }
    }
    return results;
}

int main(void) {
    printf("=== Test: Sparse Arrays ===\n");
    char* strings[] = {"aba", "baba", "aba", "xzxb"};
    char* queries[] = {"aba", "xzxb", "ab"};
    int res_count = 0;
    int* res = matchingStrings(4, strings, 3, queries, &res_count);
    assert(res[0] == 2 && res[1] == 1 && res[2] == 0);
    printf("Test Passed: Expected [2, 1, 0], Got [%d, %d, %d]\n", res[0], res[1], res[2]);
    free(res);
    return 0;
}
