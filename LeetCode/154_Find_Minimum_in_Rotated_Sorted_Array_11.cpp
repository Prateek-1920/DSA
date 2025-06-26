class Solution {
private:
    int find(vector<int>&nums,int low, int high){
        int ans = INT_MAX;
        while(low<=high){
            int mid = low+ (high-low)/2;
            ans = min(ans, nums[mid]);
            if(nums[mid]<nums[high]){
                high=mid;
            }
            else if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high--;
            }
        }
        return ans;
    }
public:
    int findMin(vector<int>& nums) {
        int ans = find(nums,0,nums.size()-1);
        return ans;
    }
};