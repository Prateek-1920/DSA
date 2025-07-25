class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_map<int,int> freq;
        int neg = 0;
        int maxneg = INT_MIN;
        for(int num : nums){
            if(num>=0){
                freq[num]++;
            }
            else{
                neg++;
                maxneg = max(maxneg,num);
            }
        }

        if(neg==nums.size()){
            return maxneg;
        }
        int ans= 0;
        for(auto &it: freq){
            ans+=it.first;
        }
        return ans;
        
    }
};