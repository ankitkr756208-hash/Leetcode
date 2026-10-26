
class Solution {
public:
    int m, n;
    long long sum = 0;

    void dfs(vector<vector<int>>& grid, int r, int c) {
        if (r < 0 || r >= m ||
            c < 0 || c >= n ||
            grid[r][c] == 0) {
            return;
        }

        sum += grid[r][c];

        // Mark visited
        grid[r][c] = 0;

        dfs(grid, r - 1, c);
        dfs(grid, r + 1, c);
        dfs(grid, r, c - 1);
        dfs(grid, r, c + 1);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();

        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] > 0) {
                    sum = 0;

                    dfs(grid, i, j);

                    if (sum % k == 0) {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};

