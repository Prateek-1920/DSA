class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        if(n<=1)return 0;
        
        int maxdif = INT_MIN;
        for(int i=0;i<n;i++){
            int diff = nums[i]-nums[(i+1)%n];
            if(abs(diff)>maxdif){
                maxdif=abs(diff);
            }
        }
        return maxdif;
    }
};