class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        vector<vector<int>> ones;
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        
        vector<vector<int>> dp = matrix;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if (matrix[i][j] == 1 && i > 0 && j > 0) {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans+=dp[i][j];
            }
        }
        return ans;
    }
};