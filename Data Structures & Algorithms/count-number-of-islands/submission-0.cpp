
class Solution {
public:
    void dfs(int i, int j, vector<vector<char>>& grid,
             vector<vector<int>>& vis, int n, int m) {
        int dx[] = {0, -1, 0, 1};
        int dy[] = {-1, 0, 1, 0};

        for (int k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && y >= 0 && x < n && y < m &&
                grid[x][y] == '1' && vis[x][y] == 0) {
                vis[x][y] = 1;
                dfs(x, y, grid, vis, n, m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;

        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    vis[i][j] = 1;
                    dfs(i, j, grid, vis, n, m);
                    ans++;
                }
            }
        }

        return ans;
    }
};
