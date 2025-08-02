class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        if((accumulate(basket1.begin(),basket1.end(),0LL) + accumulate(basket2.begin(),basket2.end(),0LL))%2!=0){
            return -1;
        }
        unordered_map<int,int> freq;
        int minele = INT_MAX;

        for(int i : basket1){
            minele = min(minele,i);
            freq[i]++;
        }
        for(int j : basket2){
            minele = min(minele,j);
            freq[j]--;
        }
        vector<int> extra;
        for(auto &it : freq){
            if(it.second%2!=0){
                return -1;
            }
            if(it.second==0){
                continue;
            }
            for(int i=0;i<abs(it.second/2);i++){
                extra.push_back(it.first);
            }
            
        }
        sort(extra.begin(),extra.end());
        long long ans = 0;
        for(int i=0;i<extra.size()/2;i++){
            ans += min(extra[i] , 2*minele);
        }
        return ans;

    }
};