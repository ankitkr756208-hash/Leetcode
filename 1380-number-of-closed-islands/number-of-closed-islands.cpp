class Solution {
public:
    int m, n;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        // Base case: out of bounds or water
        if (r < 0 || c < 0 || r >= m || c >= n ||
            grid[r][c] == 1) {
            return;
        }

        // Mark this land cell as visited
        grid[r][c] = 1;

        // Explore all four directions
        dfs(grid, r - 1, c); // Up
        dfs(grid, r + 1, c); // Down
        dfs(grid, r, c - 1); // Left
        dfs(grid, r, c + 1); // Right
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // Remove all islands connected to the boundary
        for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }

        int count = 0;

        // Count the remaining islands
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    count++;
                    dfs(grid, i, j);
                }
            }
        }

        return count;
    }
};