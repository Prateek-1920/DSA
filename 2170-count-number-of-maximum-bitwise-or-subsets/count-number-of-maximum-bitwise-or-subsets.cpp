class Solution {
private:
    int subset(int index, vector<int>&nums, int curr_or, int &maxor){
        if(index==nums.size()){
            if(curr_or==maxor){
                return 1;
            }
            else{
                return 0;
            }
        }
        int take = subset(index+1,nums,curr_or|nums[index],maxor);
        int nottake = subset(index+1,nums,curr_or,maxor);
        return take + nottake;
    }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_ans = 0;
        for(auto i : nums){
            max_ans |= i;
        }

        return subset(0,nums,0,max_ans);
    }
};