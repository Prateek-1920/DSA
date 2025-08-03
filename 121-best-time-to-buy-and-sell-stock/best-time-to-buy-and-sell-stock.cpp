class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minele = prices[0];
        int profit = 0;
        for(int i:prices){
            minele = min(minele,i);
            profit = max(profit,i-minele);
        }
        return profit;
    }
};