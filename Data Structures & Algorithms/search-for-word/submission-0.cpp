class Solution {
public:
    vector<int>row = {1, 0, -1, 0};
    vector<int>col = {0, 1, 0, -1};
    bool helper(vector<vector<char>>& board, string word, int n, int m, int r, int c, int i){
        if(i == word.length())return true;
        if(r < 0 || r >= n || c < 0 || c >= m)
            return false;

        if(board[r][c] != word[i])
            return false;
        char temp = board[r][c];
        board[r][c] = '#';
        for(int idx = 0; idx<4; idx++){
            int nr = r+row[idx];
            int nc = c+col[idx];
            if(helper(board, word, n, m, nr, nc, i+1)){
                return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(helper(board, word, n, m, i, j, 0))return true;
            }
        }
        return false;
    }
};
