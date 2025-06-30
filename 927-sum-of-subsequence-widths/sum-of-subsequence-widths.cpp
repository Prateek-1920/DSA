class Solution {
public:
    int sumSubseqWidths(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size()-1;
        long long ans = 0LL;
        long long mod = 1e9+7;
        int n = nums.size();

        vector<long long> power(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            power[i] = (power[i-1]*2) % mod;
        }

        for(int i=0;i<nums.size();i++){
            long long width = (nums[i] - nums[n-i-1]);
            ans = (ans+width*power[i])%mod;
        }
        return ans;

    }
};