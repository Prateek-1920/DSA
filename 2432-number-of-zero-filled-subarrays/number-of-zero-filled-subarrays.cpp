class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<long long> cons(n,-1);
        
        if(nums[0]==0){
            cons[0]=1;
        }

        for(int i=1;i<n;i++){
            if(nums[i]==0){
                if(cons[i-1]==-1){
                    cons[i]=1;
                }
                else{
                    cons[i] = 1 + cons[i-1];
                }
            }
        }
        long long ans = 0;
        for(long long i : cons){
            if(i!=-1){
                ans+=i;
            }
        }
        return ans;
    }
};