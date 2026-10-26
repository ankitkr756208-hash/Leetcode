
class Solution {
public:
    int n, m;

    bool dfs(vector<vector<int>>& grid, int r, int c) {

        // If we go outside the grid, the island is not closed
        if (r < 0 || r >= n || c < 0 || c >= m) {
            return false;
        }

        // Water or already visited land
        if (grid[r][c] == 1) {
            return true;
        }

        // Mark land as visited
        grid[r][c] = 1;

        // Explore all four directions
        bool left = dfs(grid, r, c - 1);
        bool right = dfs(grid, r, c + 1);
        bool up = dfs(grid, r - 1, c);
        bool down = dfs(grid, r + 1, c);

        return left && right && up && down;
    }

    int closedIsland(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 0) {

                    if (dfs(grid, i, j)) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

