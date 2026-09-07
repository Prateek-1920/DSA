class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int minele = *min_element(nums.begin(),nums.end());
        int maxele = *max_element(nums.begin(),nums.end());

        set<int> hash;
        vector<int> ans;
        for(auto i : nums){
            hash.insert(i);
        }

        for(int i=minele;i<maxele;i++){
            if(hash.find(i)==hash.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};