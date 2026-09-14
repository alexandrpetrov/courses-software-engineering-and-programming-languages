#include <stdio.h>

int main(void) {
    int changes[] = {120, -45, -90, 200, 0, -310, 75};
    int count = (int)(sizeof(changes) / sizeof(changes[0]));
    int position = 0;
    int level = 250;
    int applied = 0;
    int refused = 0;
    int candidate = 0;

START:
    if (position >= count) goto SUMMARY;
    if (changes[position] == 0) goto IGNORE_CHANGE;
    candidate = level + changes[position];
    if (candidate < 0) goto REFUSE_CHANGE;
    if (candidate > 500) goto REFUSE_CHANGE;
    goto APPLY_CHANGE;

APPLY_CHANGE:
    level = candidate;
    applied++;
    if (level == 0) goto AT_LOWER_LIMIT;
    if (level == 500) goto AT_UPPER_LIMIT;
    goto ADVANCE;

AT_LOWER_LIMIT:
    printf("Lower limit reached at event %d.\n", position + 1);
    goto ADVANCE;

AT_UPPER_LIMIT:
    printf("Upper limit reached at event %d.\n", position + 1);
    goto ADVANCE;

REFUSE_CHANGE:
    refused++;
    goto ADVANCE;

IGNORE_CHANGE:
    printf("Event %d made no change.\n", position + 1);

ADVANCE:
    position++;
    goto START;

SUMMARY:
    printf("Final account: %d.\n", level);
    printf("Applied: %d; refused: %d.\n", applied, refused);
    if (refused > applied) goto MANY_REFUSALS;
    goto END;

MANY_REFUSALS:
    printf("More events were refused than applied.\n");

END:
    return 0;
}
