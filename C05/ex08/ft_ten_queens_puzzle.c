#include <unistd.h>
#include <stdbool.h>

// This is overcomplicated; you could just use indices from loops instead of y.
typedef struct s_point
{
    int x;
    int y;
} t_point;

bool is_valid(t_point *queens, size_t queens_length, t_point p)
{
    for (size_t i = 0; i < queens_length; ++i)
        if (queens[i].x == p.x || queens[i].y == p.y)
            return false;
        else if (queens[i].x - p.x == queens[i].y - p.y)
            return false;
        else if (queens[i].x - p.x == p.y - queens[i].y)
            return false;
    return true;
}

bool find_queens(t_point *queens, size_t queens_length, size_t row, size_t size)
{
    if (row >= size)
        return true;

    for (size_t col = 0; col < size; ++col)
    {
        t_point p = { col, row };
        if (is_valid(queens, queens_length, p))
        {
            queens[queens_length] = p;
            if (find_queens(queens, queens_length + 1, row + 1, size))
                return true;
        }
    }
    return false;
}

#include <stdlib.h>
#include <string.h>

void display_queens(t_point* queens, size_t size)
{
    char* board_mem = malloc(size * size);
    memset(board_mem, 'O', size * size);
    char** board = malloc(size * sizeof board[0]);
    for (size_t i = 0; i < size; ++i)
        board[i] = board_mem + i * size;
    for (size_t i = 0; i < size; ++i)
        board[queens[i].y][queens[i].x] = 'X';
    for (size_t i = 0; i < size; ++i) {
        for (size_t j = 0; j < size; ++j)
            write(1, &board[i][j], 1);
        write(1, "\n", 1);
    }
    free(board_mem);
    free(board);
}

#define N 10

int main(void)
{
    t_point queens[N] = {0};
    find_queens(queens, 0, 0, N);
    display_queens(queens, N);
}
