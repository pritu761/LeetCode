class Solution {
public:
    int m, n;
    vector<pair<int, int>> directions{{1,0}, {-1,0}, {0,1}, {0,-1}};

    bool find(vector<vector<char>>& board, int i, int j, int idx, const string &word) {
        // Base case: full word matched
        if (idx == word.length())
            return true;

        // Boundary and character match check
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[idx])
            return false;

        // Mark cell as visited and save original value locally
        char temp = board[i][j];
        board[i][j] = '$';

        // Explore 4 directions
        for (const auto& [dx, dy] : directions) {
            int new_i = i + dx;
            int new_j = j + dy;

            if (find(board, new_i, new_j, idx + 1, word))
                return true;
        }

        // Backtrack: restore original character
        board[i][j] = temp;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }
};