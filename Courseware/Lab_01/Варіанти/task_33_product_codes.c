#include <stdio.h>

int main(void) {
    int candidate = 20;
    int last = 58;
    int original = 0;
    int working = 0;
    int digit_sum = 0;
    int selected = 0;
    int total = 0;

CHECK_CANDIDATE:
    if (candidate > last) goto REPORT;
    if (candidate % 5 == 0) goto NEXT_CANDIDATE;
    original = candidate;
    working = candidate;
    digit_sum = 0;
    goto CHECK_DIGIT;

ADD_DIGIT:
    digit_sum += working % 10;
    working /= 10;

CHECK_DIGIT:
    if (working > 0) goto ADD_DIGIT;
    if (digit_sum < 6) goto NEXT_CANDIDATE;
    if (digit_sum % 2 == 0) goto EVEN_DIGIT_SUM;
    goto ODD_DIGIT_SUM;

ODD_DIGIT_SUM:
    total += original;
    selected++;
    goto NEXT_CANDIDATE;

EVEN_DIGIT_SUM:
    total += original * 2;
    selected++;
    goto NEXT_CANDIDATE;

NEXT_CANDIDATE:
    candidate++;
    goto CHECK_CANDIDATE;

REPORT:
    if (selected == 0) goto NO_MATCHES;
    printf("Selected product codes: %d.\n", selected);
    printf("Weighted identifier total: %d.\n", total);
    goto END;

NO_MATCHES:
    printf("No identifiers matched the rules.\n");

END:
    return 0;
}
