class Solution {
public:

    bool isValid(vector<vector<char>>& board, int row, int column, char d) {

        // Check column
        for(int i = 0; i < 9; i++) {
            if(board[i][column] == d)
                return false;
        }

        // Check row
        for(int i = 0; i < 9; i++) {
            if(board[row][i] == d)
                return false;
        }

        // Find starting cell of 3x3 box
        int start_i = (row / 3) * 3;
        int start_j = (column / 3) * 3;

        // Check 3x3 box
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {

                if(board[start_i + i][start_j + j] == d)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {

                if(board[i][j] == '.') {

                    for(char d = '1'; d <= '9'; d++) {

                        if(isValid(board, i, j, d)) {

                            // Choose
                            board[i][j] = d;

                            // Explore
                            if(solve(board)) {
                                return true;
                            }

                            // Backtrack
                            board[i][j] = '.';
                        }
                    }

                    // No digit works for this cell
                    return false;
                }
            }
        }

        // No empty cells remain
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};