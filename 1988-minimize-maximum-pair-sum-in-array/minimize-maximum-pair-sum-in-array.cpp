class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int left = 0;
        int right = n-1;

        vector<int> sums;

        while(left<=right){
            sums.push_back(nums[left]+nums[right]);
            left++;
            right--;
        }

        return *max_element(sums.begin(),sums.end());
    }
};