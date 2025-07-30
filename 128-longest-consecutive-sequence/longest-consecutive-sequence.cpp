class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int num : nums){
            set.insert(num);
        }
        int longest = 0;
        for(int num : set){
            if(set.find(num-1)==set.end()){
                int curr = num;
                int currlength = 1;
                while(set.find(curr+1)!=set.end()){
                    curr++;
                    currlength++;
                }
                longest = max(longest,currlength);
            }
        }
        return longest;
    }
};