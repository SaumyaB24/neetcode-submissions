class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // Rows
        for (int i = 0; i < 9; i++) {
            vector<int> temp(10, 0);

            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';

                if (temp[num] != 0)
                    return false;

                temp[num] = 1;
            }
        }

        // Columns
        for (int j = 0; j < 9; j++) {
            vector<int> temp(10, 0);

            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.') continue;

                int num = board[i][j] - '0';

                if (temp[num] != 0)
                    return false;

                temp[num] = 1;
            }
        }

        // 3 × 3 grids
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {

                vector<int> temp(10, 0);

                for (int x = i; x < i + 3; x++) {
                    for (int y = j; y < j + 3; y++) {

                        if (board[x][y] == '.') continue;

                        int num = board[x][y] - '0';

                        if (temp[num] != 0)
                            return false;

                        temp[num] = 1;
                    }
                }
            }
        }

        return true;
    }
};