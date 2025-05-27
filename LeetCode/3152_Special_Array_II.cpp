class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int>bad(n-1,0);
        for(int i=0;i<n-1;i++){
           bad[i] = ((nums[i] % 2) == (nums[i+1] % 2)) ? 1 : 0;
        }

        vector<int> prefix(n,0);
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1]+bad[i-1];
        }   

        vector<bool> ans;

        for(auto &it : queries){
            int left = it[0];
            int right = it[1];
            if(prefix[right]-prefix[left]==0){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
