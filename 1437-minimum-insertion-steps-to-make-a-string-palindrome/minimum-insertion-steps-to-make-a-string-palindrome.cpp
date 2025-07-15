class Solution {
int lps(string text1, string text2){
    int m = text1.length();
    int n = text2.length();

    vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
    for(int i=0;i<=m;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<=n;j++){
        dp[0][j]=0;
    }

    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(text1[i-1]==text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    }
    return dp[m][n];
}
public:
    int minInsertions(string s) {
        int len = s.length();
        string l = s;
        reverse(l.begin(),l.end());

        return len - lps(s,l);
        
    }
};