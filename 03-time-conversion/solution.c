#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

char* timeConversion(char* s) {
    char* result = (char*)malloc(9);
    int hh, mm, ss;
    char period[3];
    sscanf(s, "%2d:%2d:%2d%2s", &hh, &mm, &ss, period);

    if (strcmp(period, "AM") == 0) {
        if (hh == 12) hh = 0;
    } else {
        if (hh != 12) hh += 12;
    }
    sprintf(result, "%02d:%02d:%02d", hh, mm, ss);
    return result;
}

int main(void) {
    printf("=== Test: Time Conversion ===\n");
    // Test PM conversion
    char* t1 = timeConversion("07:05:45PM");
    assert(strcmp(t1, "19:05:45") == 0);
    printf("Test 1 Passed: 07:05:45PM -> %s\n", t1);
    free(t1);

    // Test 12 AM midnight conversion
    char* t2 = timeConversion("12:01:00AM");
    assert(strcmp(t2, "00:01:00") == 0);
    printf("Test 2 Passed: 12:01:00AM -> %s\n", t2);
    free(t2);

    // Test 12 PM noon conversion
    char* t3 = timeConversion("12:40:22PM");
    assert(strcmp(t3, "12:40:22") == 0);
    printf("Test 3 Passed: 12:40:22PM -> %s\n", t3);
    free(t3);
    return 0;
}
