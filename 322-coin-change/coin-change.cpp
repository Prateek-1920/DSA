class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount<1)return 0;
        vector<int> dp(amount+1,100000);
        dp[0] = 0;

        for(int i=1;i<amount+1;i++){
            for(int coin : coins){
                if(i-coin>=0){
                    dp[i] = min(dp[i],1+dp[i-coin]);
                }
            }
        }

        return dp[amount]==100000 ? -1 : dp[amount];
    }
};