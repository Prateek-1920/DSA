class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> diff(n,0);
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0];
            int end=queries[i][1];
            diff[start]++;
            if(end+1<n){
                diff[end+1]--;
            }
        }
        vector<int>prefix(n,0);
        prefix[0]=diff[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+diff[i];
        }

        for(int i=0;i<n;i++){
            int subtract = nums[i] - prefix[i];
            if(subtract>0) return false;
        }
        return true;
    }
};
