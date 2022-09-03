/*
Return True or False if path exists from point A to B on 2D grid
if grid[x][y]==1 then you can move forward else you can't
*/
#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool findPath(int maze[][20], int n, int x, int y, int path[][20])
{
    // checking bounds
    if (x < 0 || x >= n || y < 0 || y >= n)
    {
        return false;
    }
    if (x == n - 1 && y == n - 1)
    {
        path[x][y] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;

        return true;
    }
    // as you can't move forward from 0
    // checking already traversed path
    if (maze[x][y] == 0 || path[x][y] == 1)
    {

        return false;
    }
    path[x][y] = 1;
    // Right
    if (findPath(maze, n, x, y + 1, path))
    {
        path[x][y] = 0;
        return true;
    }
    // left
    if (findPath(maze, n, x, y - 1, path))
    {
        path[x][y] = 0;
        return true;
    }
    //  bottom
    if (findPath(maze, n, x - 1, y, path))
    {
        path[x][y] = 0;
        return true;
    }
    // top
    if (findPath(maze, n, x + 1, y, path))
    {
        path[x][y] = 0;
        return true;
    }

    return false;
}

bool findPath(int maze[][20], int n)
{
    int path[20][20] = {0};
    // Keep track of current cell
    return findPath(maze, n, 0, 0, path);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = 3;
    int maze[20][20] = {{1, 1, 0}, {1, 1, 0}, {0, 1, 1}};
    cout << findPath(maze, n) << endl;

    return 0;
}