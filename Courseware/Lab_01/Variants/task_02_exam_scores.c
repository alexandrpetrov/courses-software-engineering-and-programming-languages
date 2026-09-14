#include <stdio.h>

int main(void) {
    int values[] = {44, 72, 91, 105, 68, 80, 57, 96};
    int length = (int)(sizeof(values) / sizeof(values[0]));
    int index = 0;
    int total = 0;
    int accepted = 0;
    int rejected = 0;

    goto CHECK_ITEM;

NEXT_ITEM:
    index++;

CHECK_ITEM:
    if (index >= length) goto REPORT;
    if (values[index] < 50) goto REJECT_ITEM;
    if (values[index] > 100) goto REJECT_ITEM;
    if (values[index] % 5 == 0) goto BONUS_ITEM;
    goto NORMAL_ITEM;

NORMAL_ITEM:
    total += values[index];
    accepted++;
    goto NEXT_ITEM;

BONUS_ITEM:
    total += values[index] * 2;
    accepted++;
    goto NEXT_ITEM;

REJECT_ITEM:
    rejected++;
    goto NEXT_ITEM;

REPORT:
    if (accepted == 0) goto EMPTY_REPORT;
    printf("Processed exam scores: %d accepted, %d rejected.\n",
           accepted, rejected);
    printf("Weighted total: %d.\n", total);
    if (total >= 450) goto TARGET_REACHED;
    printf("Target was not reached.\n");
    goto END;

TARGET_REACHED:
    printf("Target reached.\n");
    goto END;

EMPTY_REPORT:
    printf("No acceptable items.\n");

END:
    return 0;
}
