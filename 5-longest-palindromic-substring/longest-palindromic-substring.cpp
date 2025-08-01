class Solution {
    int palindrome(vector<vector<int>>&dp , string &s, int i, int j){
        if(i>=j){
            return dp[i][j]=1;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        if(s[i]==s[j]){
            return dp[i][j] = palindrome(dp,s,i+1,j-1);
        }
        return dp[i][j] = 0;
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int maxlen = INT_MIN;
        int start = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(palindrome(dp,s,i,j)){
                    if(maxlen < j-i+1){
                        maxlen = j-i+1;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};