class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> hash;
        for(int i : nums){
            if(i%k==0){
                hash.insert(i);
            }
        }

        for(int i=1;i<999;i++){
            if(hash.find(k*i)==hash.end()){
                return k*i;
            }
        }
        return -1;
    }
};