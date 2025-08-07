class Solution {
private:
    int dfs(int x, int y, int n, int moves, vector<vector<int>>&fruits, vector<pair<int,int>>&dirs, vector<vector<int>>&dp ){
        if(x==n-1 && y==n-1){   
            return moves== 0?0:INT_MAX;
        }
        if(x==y || moves==0){
            return INT_MAX;
        }
        if(dp[x][y]!=-1){
            return dp[x][y];
        }
        long long maxfruits = -1;
        for(auto&it : dirs){
            int newx = x+it.first;
            int newy = y+it.second;
            if(newx >=0 && newx<n && newy>=0 && newy<n){
                long long val = dfs(newx,newy,n,moves-1,fruits,dirs,dp);
                if(val!=INT_MAX){
                    maxfruits = max(maxfruits,val);
                }
            }
        }
        return dp[x][y] = (maxfruits<0? INT_MAX : maxfruits + fruits[x][y]);
    }
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();
        long long diag = 0;
        for(int i=0;i<n;i++){
            diag += fruits[i][i];
        }

        vector<pair<int,int>> dir = {{1,0},{1,-1},{1,1}};
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int top = dfs(0,n-1,n,n-1,fruits,dir,dp);

        dir = {{0,1},{1,1},{-1,1}};
        for(auto &row : dp){
            fill(row.begin(),row.end(),-1);
        }
        int bottom = dfs(n-1,0,n,n-1,fruits,dir,dp);

        return diag + top + bottom;


    }
};