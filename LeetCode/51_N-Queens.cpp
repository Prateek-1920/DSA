class Solution {
private:
    void solve(int row, int n, vector<string>& board, vector<vector<string>>& ans,vector<bool>& cols_occ, vector<bool> &main_diag, vector<bool>& anti_diag){
        if(row==n){
            ans.push_back(board);
            return ;
        }
        for(int col=0;col<n;col++){
            if(!cols_occ[col] && !main_diag[row+col] && !anti_diag[row-col +n-1] ){
                board[row][col]='Q';
                cols_occ[col] = true;
                main_diag[row+col] = true;
                anti_diag[row-col+n-1] = true;
                solve(row+1,n,board,ans,cols_occ, main_diag, anti_diag);
                board[row][col]='.';
                cols_occ[col] = false;
                main_diag[row+col] = false;
                anti_diag[row-col+n-1] = false;
            }

        }

    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;

        vector<string> board(n,string(n,'.'));

        vector<bool> cols_occ(n, false);
        vector<bool> main_diag(2 * n - 1, false);
        vector<bool> anti_diag(2 * n - 1, false);

        solve(0,n,board,ans,cols_occ, main_diag,anti_diag);

        return ans;
    }
};