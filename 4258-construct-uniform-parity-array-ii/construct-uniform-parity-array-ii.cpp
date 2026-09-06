class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minodd = INT_MAX, mineve = INT_MAX;
        int evencount = 0, oddcount = 0;
        int n = nums1.size();
        for(auto i : nums1){
            if(i%2==0){
                evencount++;
                if(i<mineve){
                    mineve = i;
                }
            }
            if(i%2!=0){
                oddcount++;
                if(i<minodd){
                    minodd = i;
                }
            }
        }
        if(n==evencount){
            return true;
        }
        if(minodd>mineve){
            return false;
        }
        return true;
    }
};