class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalsum = accumulate(nums.begin(),nums.end(),0);
        int count = 0;
        int left = 0;
        for(int i=0;i<nums.size()-1;i++){
            left += nums[i];
            int right = totalsum -left;
            if((right-left)%2==0){
                count++;
            } 
        }
        return count;
    }
};