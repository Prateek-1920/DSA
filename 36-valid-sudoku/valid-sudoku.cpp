class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        unordered_map<char,vector<vector<int>>> mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                char num = board[i][j];
                int boxnum = i/3 * n + j/3;
                if(num=='.'){
                    continue;
                }  
                for(auto&it : mp[num]){
                    int x = it[0];
                    int y = it[1];
                    int z = it[2];
                    if(x==i || y==j || boxnum==z){
                        return false;
                    }
                }
                mp[num].push_back({i,j,boxnum});
            }
        }
        return true;
    }
};