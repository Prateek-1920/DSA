class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans1;
        vector<int> ans2;
        unordered_map<int,int> mp1;
        unordered_map<int,int> mp2;

        for(auto i : nums1){
            mp1[i]++;
        }

        for(auto i : nums2){
            mp2[i]++;
        }

        for(auto &it : mp1){
            int ele = it.first;
            if(mp2.find(ele)==mp2.end()){
                ans1.push_back(ele);
            }
        }
        for(auto &it : mp2){
            int ele = it.first;
            if(mp1.find(ele)==mp1.end()){
                ans2.push_back(ele);
            }
        }

        vector<vector<int>> res;
        res.push_back(ans1);
        res.push_back(ans2);

        return res;
    }
};
