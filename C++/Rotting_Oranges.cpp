/* In a given grid, each cell can have one of three values:

the value 0 representing an empty cell;
the value 1 representing a fresh orange;
the value 2 representing a rotten orange.
Every minute, any fresh orange that is adjacent (4-directionally) to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange.  If this is impossible, return -1 instead.
 */

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int rows = grid.size();
        int cols = grid[0].size();
        if (!rows || !cols)
            return 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int fresh = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (grid[i][j] == 2)
                    q.push({i, j});
                else if (grid[i][j] == 1)
                    fresh++;
            }
        }
        int time = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                pair<int, int> p = q.front();
                int i = p.first;
                int j = p.second;
                q.pop();
                for (auto d : directions)
                {
                    int r = i + d[0];
                    int c = j + d[1];
                    if (r >= 0 && r < rows && c >= 0 && c < cols && grid[r][c] == 1)
                    {
                        grid[r][c] = 2;
                        fresh--;
                        q.push({r, c});
                    }
                }
            }
            if (q.empty())
                break;
            time++;
        }
        return fresh == 0 ? time : -1;
    }
};