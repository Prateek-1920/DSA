class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int _max= INT_MIN;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            _max = max(_max, sum);
            if(sum<0){
                sum=0;
            }
        }

        return _max;
    }
};