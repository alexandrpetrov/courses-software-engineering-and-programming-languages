#include <stdio.h>

int main(void) {
    int adjustments[] = {15, 20, -10, 35, -45, 30, -20};
    int count = (int)(sizeof(adjustments) / sizeof(adjustments[0]));
    int step = 0;
    int value = 40;
    int warnings = 0;
    int proposed = 0;

PROCESS_STEP:
    if (step >= count) goto FINISH;
    proposed = value + adjustments[step];
    if (proposed < 0) goto CLAMP_LOW;
    if (proposed > 100) goto CLAMP_HIGH;
    value = proposed;
    goto CHECK_ALERT;

CLAMP_LOW:
    value = 0;
    warnings++;
    goto NEXT_STEP;

CLAMP_HIGH:
    value = 100;
    warnings++;
    goto CHECK_ALERT;

CHECK_ALERT:
    if (value >= 85) goto ISSUE_ALERT;
    goto NEXT_STEP;

ISSUE_ALERT:
    printf("Alert at step %d: value is %d.\n", step + 1, value);
    warnings++;
    goto NEXT_STEP;

NEXT_STEP:
    step++;
    goto PROCESS_STEP;

FINISH:
    printf("Final train speed: %d.\n", value);
    printf("Warnings issued: %d.\n", warnings);
    if (warnings == 0) goto ALL_NORMAL;
    goto END;

ALL_NORMAL:
    printf("All adjustments stayed in the normal range.\n");

END:
    return 0;
}
