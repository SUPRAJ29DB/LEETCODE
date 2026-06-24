class Solution {
public:

    vector<vector<string>>ans;


void solve(int row, vector<string>& board, vector<int>& col, vector<int>& l_diag, vector<int>& r_diag, int n) {
    // Base Case: If all queens are safely placed, store the board configuration
    if (row == n) {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++) {
        // Check if placing a queen at board[row][i] is safe
        if (col[i] == 0 && l_diag[row - i + n - 1] == 0 && r_diag[row + i] == 0) {
            
            // Place the queen and mark the columns and diagonals
            board[row][i] = 'Q';
            col[i] = 1;
            l_diag[row - i + n - 1] = 1;
            r_diag[row + i] = 1;

            // Recur to place the queen in the next row
            solve(row + 1, board, col, l_diag, r_diag, n);

            // Backtrack: Remove the queen and unmark the paths
            board[row][i] = '.';
            col[i] = 0;
            l_diag[row - i + n - 1] = 0;
            r_diag[row + i] = 0;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    
    ans.clear(); 
    
    vector<string> board(n, string(n, '.'));
    
    vector<int> col(n, 0);
    vector<int> l_diag(2 * n - 1, 0);
    vector<int> r_diag(2 * n - 1, 0);

    solve(0, board, col, l_diag, r_diag, n);
    
    return ans;
}
    
};
