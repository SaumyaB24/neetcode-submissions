class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int fresh = 0, time = 0;
        queue<pair<int,int>>q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }else if(grid[i][j] == 1)fresh++;
            }
        }
        int dc[] = {0, -1, 0, 1};
        int dr[] = {1, 0, -1, 0};
        while(!q.empty() && fresh != 0){
            int k = q.size();
            for(int x = 0; x<k; x++){
                int r = q.front().first, c = q.front().second;
                q.pop();
                for(int y = 0; y<4; y++){
                    int nr = r+dr[y], nc = c+dc[y];
                    if(nr<0 || nc<0 || nr>=n || nc>=m || grid[nr][nc] == 0) continue;
                    if(grid[nr][nc] == 1){
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr,nc});
                    }
                }
            }
            time ++;
        }

        return fresh == 0? time:-1;
    }
};
