class Solution {
public:

    // Check if placing num at (row, col) is valid
    bool check(int row, int col, int num, vector<vector<char>>& board) {

        char c = num + '0';

        // Check row
        for (int j = 0; j < 9; j++) {
            if (board[row][j] == c)
                return false;
        }

        // Check column
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c)
                return false;
        }

        // Check 3x3 box
        int startRow = (row / 3) * 3;
        int startCol = (col / 3) * 3;

        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {

                if (board[i][j] == c)
                    return false;
            }
        }

        return true;
    }

    // Backtracking function
    bool solve(int row, int col, vector<vector<char>>& board) {

        // Entire board solved
        if (row == 9)
            return true;

        // Move to next row
        if (col == 9)
            return solve(row + 1, 0, board);

        // Skip filled cells
        if (board[row][col] != '.')
            return solve(row, col + 1, board);

        // Try numbers 1 to 9
        for (int num = 1; num <= 9; num++) {

            if (check(row, col, num, board)) {

                // Place number
                board[row][col] = num + '0';

                // Recur
                if (solve(row, col + 1, board))
                    return true;

                // Backtrack
                board[row][col] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {

        solve(0, 0, board);
    }
};
