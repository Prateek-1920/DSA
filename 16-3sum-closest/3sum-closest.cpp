class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = 99999;

        for(int i=0;i<n;i++){
            int left = i+1;
            int right = n-1;

            while(left<right){
                int temp = nums[i] + nums[left]+ nums[right];
                if(temp==target){
                    return target;
                }
                else if(temp>target){
                    right--;
                }
                else{
                    left++;
                }
                if (abs(temp - target) < abs(ans - target)) {
                    ans = temp;
                }
            }
        }
        return ans;
    }
};