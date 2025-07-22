class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> freq;
        int left = 0;
        int right = 0;
        int n = nums.size();
        int ans = 0;
        int sum = 0;

        while(right<n){
            freq[nums[right]]++;
            sum+=nums[right];

            while(freq[nums[right]]>1){
                freq[nums[left]]--;
                sum-=nums[left];
                left++;
            }
            
            ans = max(sum,ans);
            right++;
        }
        return ans;
    }
};