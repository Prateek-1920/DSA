class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       unordered_map<int,int> freq;
       for(auto i : arr){
            freq[i]++;
       } 

        unordered_set<int> seen;

       for(auto &it : freq){
        if(seen.find(it.second)!=seen.end()){
            return false;
        }
        seen.insert(it.second);
    }
    return true;
    }
};
