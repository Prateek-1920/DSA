class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int left = 0;
        for(int right=1;right<prices.size();right++){
            if(prices[right] == prices[right-1]-1){
                continue;
            }
            else{
                long long n = right-left;
                ans = ans + (n*(n+1))/2;
                left = right;
            }
        }
        ans += (prices.size()-left) * (prices.size()-left+1)/2;
        return ans;

    }
};