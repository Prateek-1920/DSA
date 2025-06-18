class Solution {
private:
    bool checkdiff(int a, int b, int c, int k){
        if(abs(a-b)<=k && abs(a-c)<=k && abs(b-c)<=k){
            return true;
        }
        return false;
    }
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=2;i<nums.size();i=i+3){
            vector<int> temp;
            if(checkdiff(nums[i],nums[i-1],nums[i-2],k)){
                temp = {nums[i],nums[i-1],nums[i-2]};
                ans.push_back(temp);
            }
            else{
                return {};
            }
        }
        return ans;
    }
};