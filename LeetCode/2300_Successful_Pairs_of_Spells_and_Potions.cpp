class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n = spells.size();
        int m = potions.size();
        vector<int> pairs;
        sort(potions.begin(),potions.end());
        for(int i=0;i<n;i++){
            long long strength = spells[i];
            int low= 0;
            int high = m-1;
            while(low<=high){
                int mid = low + (high-low)/2;
                long long mul = strength*potions[mid];
                if(mul<success){
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            int ans = 0;
            if(low==high){
                pairs.push_back(ans);
            }
            else{
                pairs.push_back(m-low);
            }
        }
        return pairs;
    }
};
