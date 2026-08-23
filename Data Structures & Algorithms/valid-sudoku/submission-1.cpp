class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int r[10][10] = {0};
        int c[10][10] = {0};
        int b[10][10] = {0};

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                else{
                    int a = board[i][j]-'0';
                    r[i][a]++;
                    c[j][a]++;
                    int block = (i/3)*3+j/3;
                    b[block][a]++;
                    if(r[i][a]>1||c[j][a]>1||b[block][a]>1){
                        return false;
                    }
                }
            }
        }
        return true; 
    }
};
