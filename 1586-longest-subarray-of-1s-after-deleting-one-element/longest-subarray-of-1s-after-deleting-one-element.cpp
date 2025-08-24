class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        // int right = 0;
        int ans = 0;
        int zero_count = 0;

        if(nums[0]==0){
            while(nums[left]!=0){
                left++;
            }
        }

        for(int right =left;right<n;right++){
            if(nums[right]==0){
                zero_count++;
                if(zero_count>1){
                    ans = max(ans , right-left-1);
                    while(zero_count>1){
                        if(nums[left]==0){
                            zero_count--;
                        }
                        left++;
                    }
                }
            }
            else{
                ans = max(ans , right-left);
            }
        }
        return ans;
    }
};