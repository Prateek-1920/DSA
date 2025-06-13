class Solution {
private:
    bool dfs(int x, int y, vector<vector<char>>& board, int index, string word){
        if(index == word.size()-1){
            return board[x][y] == word[index];
        }
        if (board[x][y] != word[index]) return false;

        char temp = board[x][y];
        board[x][y] = '#';
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &it : dir){
            int newx = x + it.first;
            int newy = y + it.second;
            if(newx>=0 && newy>=0 && newx<board.size() && newy<board[0].size() && board[newx][newy]!='#'){
                {
                    if(dfs(newx,newy,board,index+1,word))return true;
                }
            }
        }
        board[x][y] = temp;
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<pair<int,int>> indices;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(dfs(i,j,board,0,word))return true;
                }
            }
        }
        return false;
    }
};