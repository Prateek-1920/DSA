class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    if(i>0){
                        dp[i][j]=dp[i-1][j]+1;
                    }
                    else{
                        dp[i][j] = 1;
                    }
                }
            }
        }

        int ans = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int height = dp[i][j];
                for(int k=j;k>=0;k--){
                    height = min(height,dp[i][k]);
                    ans+=height;
                }
            }
        }
        return ans;
    }
};