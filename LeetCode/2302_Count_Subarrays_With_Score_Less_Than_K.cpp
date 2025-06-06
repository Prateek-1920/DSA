class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int left = 0;
        long long sum = 0;
        long long  result = 0;
        for(int right = 0;right<nums.size();right++){
            sum+=nums[right];
            while(sum*(right-left+1)>=k){
                sum-=nums[left];
                left++;
            }
            result+=(right-left+1);
        }
        return result;
    }
};
