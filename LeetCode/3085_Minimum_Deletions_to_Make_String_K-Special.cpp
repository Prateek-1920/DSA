class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char,int> freq;
        for(char c : word){
            freq[c]++;
        }

        int ans = INT_MAX;
        // sort(freq.begin(),freq.end());

        for(auto &it : freq){
            int ele = it.first;
            int lowest = it.second;
            int count = 0;
            for(auto &j : freq){
                if(j.first!=ele){
                    if(j.second>lowest+k){
                        count+=j.second-lowest-k;
                    }
                    else if(j.second<lowest){
                        count+=j.second;
                    }
                    else if(lowest<j.second<lowest+k){
                        continue;
                    }
                }
            }
            ans = min(ans,count);
        }
    return ans;
    }
};