class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int count = 0;

        for(int i=0;i<n-2;i++){
            if(nums[i]==1){
                continue;
            }
            else{
                int j=0;
                while(j<3){
                    nums[i+j] = 1^nums[i+j];
                    j++;
                }
                count++;
            }
        }
        if(nums[n-2]==1 && nums[n-1]==1){
            return count;
        }
        return -1;
    }
};