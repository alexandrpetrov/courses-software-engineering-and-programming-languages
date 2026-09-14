#include <stdio.h>

int main(void) {
    int grid[4][3] = {{12, 0, 8}, {-1, 15, 6}, {9, 11, 0}, {5, -1, 14}};
    int row = 0;
    int column = 0;
    int total = 0;
    int usable = 0;
    int blocked = 0;

ROW_CHECK:
    if (row >= 4) goto REPORT;
    column = 0;
    goto COLUMN_CHECK;

NEXT_COLUMN:
    column++;

COLUMN_CHECK:
    if (column >= 3) goto NEXT_ROW;
    if (grid[row][column] < 0) goto BLOCKED_CELL;
    if (grid[row][column] == 0) goto EMPTY_CELL;
    if (grid[row][column] >= 12) goto SPECIAL_CELL;
    goto NORMAL_CELL;

NORMAL_CELL:
    total += grid[row][column];
    usable++;
    goto NEXT_COLUMN;

SPECIAL_CELL:
    total += grid[row][column] * 2;
    usable++;
    goto NEXT_COLUMN;

EMPTY_CELL:
    goto NEXT_COLUMN;

BLOCKED_CELL:
    blocked++;
    goto NEXT_COLUMN;

NEXT_ROW:
    row++;
    goto ROW_CHECK;

REPORT:
    printf("Total visitors: %d.\n", total);
    printf("Usable cells: %d; blocked cells: %d.\n", usable, blocked);
    if (blocked == 0) goto CLEAR_GRID;
    goto END;

CLEAR_GRID:
    printf("The entire grid is accessible.\n");

END:
    return 0;
}
