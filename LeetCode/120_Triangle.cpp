class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m = triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,0));

        dp[0][0] = triangle[0][0];

        for(int i=1;i<m;i++){
            for(int j=0;j<=i;j++){
                if(j==0){
                    dp[i][j]=triangle[i][j] + dp[i-1][j];
                }
                else if(j==i){
                     dp[i][j]=triangle[i][j] + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = triangle[i][j] + min(dp[i-1][j],dp[i-1][j-1]);
                }
            }
        }

        return *min_element(dp[m-1].begin(),dp[m-1].end());
    }
};