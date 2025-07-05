class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int,int> freq;
        int ans = -1;
        for(int i : arr){
            freq[i]++;
        }
        
        for(auto &it : freq){
            if(it.first==it.second){
                ans = max(ans,it.first);
            }
        }
        return ans;
    }
};