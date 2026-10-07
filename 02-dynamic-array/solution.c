#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
    int* data;
    int size;
    int capacity;
} Vector;

void vec_init(Vector* v) {
    v->size = 0;
    v->capacity = 4;
    v->data = (int*)malloc(sizeof(int) * v->capacity);
}

void vec_push(Vector* v, int val) {
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, sizeof(int) * v->capacity);
    }
    v->data[v->size++] = val;
}

int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    (void)queries_columns;
    Vector* arr = (Vector*)malloc(sizeof(Vector) * n);
    for (int i = 0; i < n; i++) vec_init(&arr[i]);

    int lastAnswer = 0;
    int* answers = (int*)malloc(sizeof(int) * queries_rows);
    int ans_idx = 0;

    for (int i = 0; i < queries_rows; i++) {
        int type = queries[i][0];
        int x = queries[i][1];
        int y = queries[i][2];
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            vec_push(&arr[idx], y);
        } else if (type == 2) {
            lastAnswer = arr[idx].data[y % arr[idx].size];
            answers[ans_idx++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) free(arr[i].data);
    free(arr);
    *result_count = ans_idx;
    return answers;
}

int main(void) {
    printf("=== Test: Dynamic Array ===\n");
    int n = 2;
    int q0[] = {1, 0, 5};
    int q1[] = {1, 1, 7};
    int q2[] = {1, 0, 3};
    int q3[] = {2, 1, 0};
    int q4[] = {2, 1, 1};
    int* queries[5] = {q0, q1, q2, q3, q4};

    int result_count = 0;
    int* res = dynamicArray(n, 5, 3, queries, &result_count);
    assert(result_count == 2);
    assert(res[0] == 7 && res[1] == 3);
    printf("Test Passed: Expected [7, 3], Got [%d, %d]\n", res[0], res[1]);
    free(res);
    return 0;
}
