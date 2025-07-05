class Solution {
    void backtrack(int idx, vector<int>& arr, int target, vector<int> temp, vector<vector<int>> &ans, int currsum){
        if(currsum==target){
            ans.push_back(temp);
            return;
        }
        if(currsum>target || idx==arr.size()){
            return;
        }
        temp.push_back(arr[idx]);
        currsum+=arr[idx];
        backtrack(idx,arr,target,temp,ans,currsum);
        temp.pop_back();
        currsum-=arr[idx];
        backtrack(idx+1,arr,target,temp,ans,currsum);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        backtrack(0,candidates,target,{},ans,0);
        return ans;
    }
};