#include <stdio.h>
#include <stdlib.h>

#define MAX_ROWS 100
#define MAX_COLS 100

struct Point {
    int row;
    int col;
};

struct Node {
    struct Point point;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

void initializeStack(struct Stack* stack) {
    stack->top = NULL;
}

int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

void push(struct Stack* stack, struct Point point) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->point = point;
    newNode->next = stack->top;
    stack->top = newNode;
}

struct Point pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        struct Point emptyPoint = {-1, -1};
        return emptyPoint;
    }

    struct Node* temp = stack->top;
    struct Point poppedPoint = temp->point;
    stack->top = temp->next;
    free(temp);

    return poppedPoint;
}

void find_paths_with_treasures(int maze[MAX_ROWS][MAX_COLS], int rows, int cols, int start_row, int start_col) {
    struct Stack stack;
    initializeStack(&stack);

    struct Point startPoint = {start_row, start_col};
    push(&stack, startPoint);

    int visited[MAX_ROWS][MAX_COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            visited[i][j] = 0;
        }
    }

    visited[start_row][start_col] = 1;

    while (!isEmpty(&stack)) {
        struct Point currentPoint = pop(&stack);
        int row = currentPoint.row;
        int col = currentPoint.col;

        if (maze[row][col] == 3) {
            printf("Path with Treasure: ");
            struct Node* temp = stack.top;
            while (temp != NULL) {
                printf("(%d, %d) -> ", temp->point.row, temp->point.col);
                temp = temp->next;
            }
            printf("(%d, %d)\n", row, col);
        }

        int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
        for (int i = 0; i < 4; i++) {
            int newRow = row + directions[i][0];
            int newCol = col + directions[i][1];

            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols &&
                maze[newRow][newCol] != 1 && !visited[newRow][newCol]) {
                struct Point newPoint = {newRow, newCol};
                push(&stack, newPoint);
                visited[newRow][newCol] = 1;
            }
        }
    }

    printf("No Path with Treasure Found.\n");
}

int main() {
    int maze[MAX_ROWS][MAX_COLS];
    int rows, cols, start_row, start_col;

    printf("Enter the Number of Rows and Columns of the Maze: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter the Maze:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &maze[i][j]);
        }
    }

    printf("Enter the Starting Position (Row and Column): ");
    scanf("%d %d", &start_row, &start_col);

    find_paths_with_treasures(maze, rows, cols, start_row, start_col);

    return 0;
}
