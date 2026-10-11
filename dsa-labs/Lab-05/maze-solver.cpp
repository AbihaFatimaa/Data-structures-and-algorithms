#include <iostream>
using namespace std;

struct Pair
{
    int i, j;
};

Pair arr[50];
int pathIndex = 0;

bool solve_maze(char maze[6][6], Pair s, Pair d, int row, int col)
{
    // Base case: destination reached
    if (maze[s.i][s.j] == 'T')
    {
        arr[pathIndex++] = s;
        return true;
    }

    // Mark the current cell as visited
    char original = maze[s.i][s.j];
    maze[s.i][s.j] = 'V';

    Pair next;

    // 1. Move UP
    if (s.i - 1 >= 0 &&
        (maze[s.i - 1][s.j] == ' ' ||
         maze[s.i - 1][s.j] == 'T'))
    {
        next = {s.i - 1, s.j};

        if (solve_maze(maze, next, d, row, col))
        {
            arr[pathIndex++] = s;
            return true;
        }
    }

    // 2. Move LEFT
    if (s.j - 1 >= 0 &&
        (maze[s.i][s.j - 1] == ' ' ||
         maze[s.i][s.j - 1] == 'T'))
    {
        next = {s.i, s.j - 1};

        if (solve_maze(maze, next, d, row, col))
        {
            arr[pathIndex++] = s;
            return true;
        }
    }

    // 3. Move RIGHT
    if (s.j + 1 < col &&
        (maze[s.i][s.j + 1] == ' ' ||
         maze[s.i][s.j + 1] == 'T'))
    {
        next = {s.i, s.j + 1};

        if (solve_maze(maze, next, d, row, col))
        {
            arr[pathIndex++] = s;
            return true;
        }
    }

    // 4. Move DOWN
    if (s.i + 1 < row &&
        (maze[s.i + 1][s.j] == ' ' ||
         maze[s.i + 1][s.j] == 'T'))
    {
        next = {s.i + 1, s.j};

        if (solve_maze(maze, next, d, row, col))
        {
            arr[pathIndex++] = s;
            return true;
        }
    }

    // No path found from this cell
    maze[s.i][s.j] = original;
    return false;
}

int main()
{
    char maze1[6][6] = {
        {' ', '*', ' ', '*', ' ', ' '},
        {' ', '*', ' ', '*', ' ', ' '},
        {'P', ' ', ' ', ' ', '*', ' '},
        {'*', ' ', '*', '*', '*', ' '},
        {' ', ' ', ' ', ' ', '*', 'T'},
        {'*', ' ', ' ', ' ', ' ', ' '}
    };

    Pair start = {2, 0};
    Pair dest = {4, 5};

    cout << "Maze 1" << endl;

    pathIndex = 0;

    if (solve_maze(maze1, start, dest, 6, 6))
    {
        cout << "Solved" << endl;

        cout << "Path (reverse order): ";

        for (int j = 0; j < pathIndex; j++)
        {
            cout << "(" << arr[j].i
                 << "," << arr[j].j << ") ";

            if (j < pathIndex - 1)
                cout << "<- ";
        }
        cout << endl;
    }
    else
    {
        cout << "UnSolved" << endl;
    }

    return 0;
}
