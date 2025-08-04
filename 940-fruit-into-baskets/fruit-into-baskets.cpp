class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int,int> mp;
        int n = fruits.size();
        int left = 0;
        int right = 0;
        int maxcount = INT_MIN;
        while(right<n){
            int type = fruits[right];
            mp[type]++;
            if(mp.size()>2){
                while(mp.size()>2){
                    mp[fruits[left]]--;
                    if(mp[fruits[left]]==0){
                        mp.erase(fruits[left]);
                    }
                    left++;
                }
            }
            maxcount=max(right-left+1,maxcount);
            right++;
        }
        return maxcount;
    }
};