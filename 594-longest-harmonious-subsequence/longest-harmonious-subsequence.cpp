class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int i : nums){
            freq[i]++;
        }
        int ans = 0;

        for(auto i : nums){
            if(freq.find(i+1)!=freq.end()){
                ans = max(ans, freq[i]+freq[i+1]);
            }
        }

        return ans;
    }
};