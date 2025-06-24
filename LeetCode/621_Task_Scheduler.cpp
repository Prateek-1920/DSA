class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        int max_freq = INT_MIN;
        for(char c : tasks){
            freq[c]++;
            if(freq[c]>max_freq){
                max_freq= freq[c];
            }
        }

        int max_freq_count = 0;
        for(auto &it : freq){
            if(it.second==max_freq){
                max_freq_count++;
            }
        }

        int size= tasks.size();
        int ans= max(size, ((max_freq-1)*(n+1) + max_freq_count));
        return ans;
    }
};