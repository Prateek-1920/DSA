class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){q.push({i,0});board[i][0]='#';}
            if(board[i][n-1]=='O'){q.push({i,n-1});board[i][n-1]='#';}
        }

        for(int i=0;i<n;i++){
            if(board[0][i]=='O'){q.push({0,i});board[0][i]='#';}
            if(board[m-1][i]=='O'){q.push({m-1,i});board[m-1][i]='#';}
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(auto &it : dir){
                    int newx = x+it.first;
                    int newy = y+it.second;
                    if(newx>=0 && newx <m && newy>=0 && newy<n && board[newx][newy]=='O'){
                        board[newx][newy]='#';
                        q.push({newx,newy});
                    }
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};