class Solution {
    int helper(vector<int>&nums,int start, int end){
        int n = nums.size();
        vector<int> dp(end-start,0);
        dp[0]=nums[start];
        dp[1]=max(nums[start],nums[start+1]);

        for(int i=2;i<end-start;i++){
            int take = nums[i+start]+dp[i-2];
            int nottake = dp[i-1];
            dp[i] = max(take,nottake);
        }

        return dp[end-start-1];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        if(n==2)return max(nums[0],nums[1]);

        vector<int> dp1(n,0);
        vector<int> dp2(n,0);

        int n1 = helper(nums,0,n-1); 
        int n2 = helper(nums,1,n);

        return max(n1,n2); 

    }
};