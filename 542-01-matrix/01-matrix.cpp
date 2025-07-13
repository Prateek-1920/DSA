class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> dp(rows,vector<int>(cols,INT_MAX));

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dp[i][j]=0;
                }
            }
        }
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto &it : dir){
                int newx = x+it.first;
                int newy = y+it.second;
                int dist = dp[x][y]+1;
                if(newx>=0 && newx<rows && newy>=0 && newy<cols && dp[newx][newy]>dist){
                    q.push({newx,newy});
                    dp[newx][newy] = dist;
                }
            }
        }
        return dp;
    }
};