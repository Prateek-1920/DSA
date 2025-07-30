class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0]=1;
        int curr = 0;
        int count = 0;
        for(int n : nums){
            curr +=n;
            if(freq.find(curr-k)!=freq.end()){
                count += freq[curr-k];
            }
            freq[curr]++;
        }
        return count;
    }
};