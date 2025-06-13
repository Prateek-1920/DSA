class Solution {
private:
    void recurse(int index, vector<int> &current, vector<vector<int>> &subsets, vector<int>&nums){
        if(index==nums.size()){
            subsets.push_back(current);
            return;
        }
        recurse(index+1,current,subsets,nums);
        current.push_back(nums[index]);
        recurse(index+1,current,subsets,nums);
        current.pop_back();
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> subsets;
        vector<int> current = {};
        int index = 0;
        recurse(index,current,subsets,nums);
        return subsets;
    }
};