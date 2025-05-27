class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> array;
        for(int i=0;i<n;i++){
            array.push_back({nums[i],i});
        }

        sort(array.begin(),array.end());

        vector<bool> marked(n,false);
        long long  score = 0;
        for(auto &it : array){
            int val = it.first;
            int idx = it.second;
            if(marked[idx]==false){
                score+=val;
                if(idx+1<n){
                    marked[idx+1]=true;
                }
                if(idx-1>=0){
                    marked[idx-1]=true;
                }
            }
        }
        return score;
    }
};
