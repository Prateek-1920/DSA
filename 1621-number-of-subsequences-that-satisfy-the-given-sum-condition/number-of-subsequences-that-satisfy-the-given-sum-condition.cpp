class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        int count = 0;
        int left = 0;
        int right = nums.size()-1;
        int mod = 1e9+7;

        sort(nums.begin(),nums.end());

        vector<int> power(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            power[i] = (2 * power[i-1]) % mod;
        }

        while(left<=right){
           if(nums[right]+nums[left]<=target){
            count = (count+power[right-left]) %  mod;
            left++;
           }
           else{
            right--;
           }
        }
        return count;
    }
};