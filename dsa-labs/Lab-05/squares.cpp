
#include <iostream>
using namespace std;

int countSquares(int k, int cx, int cy, int x, int y)
{
    int count = 0;

    // Check whether the point lies inside or on the square
    if (cx - k <= x && x <= cx + k &&
        cy - k <= y && y <= cy + k)
    {
        count = 1;
    }

    // Base case: size 1 cannot generate smaller squares
    if (k == 1)
    {
        return count;
    }

    int small = k / 2;

    // Recursively check all four corner squares
    count += countSquares(small, cx - k, cy - k, x, y);
    count += countSquares(small, cx + k, cy - k, x, y);
    count += countSquares(small, cx - k, cy + k, x, y);
    count += countSquares(small, cx + k, cy + k, x, y);

    return count;
}

int main()
{
    int k, x, y;
    cin >> k >> x >> y;

    cout << countSquares(k, 1024, 1024, x, y) << endl;

    return 0;
}
