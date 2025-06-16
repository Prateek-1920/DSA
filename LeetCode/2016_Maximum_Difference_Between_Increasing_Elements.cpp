// class Solution {
// public:
//     int maximumDifference(vector<int>& nums) {
//         int maxdiff = -1;
//         for(int i=0;i<nums.size();i++){
//             for(int j=i+1;j<nums.size();j++){
//                 if(nums[j]>nums[i]){
//                     maxdiff = max(maxdiff,nums[j]-nums[i]);
//                 }
//             }
//         }
//         return maxdiff;
//     }
// };


class Solution {
public:
    int maximumDifference(vector<int>& nums) {
       int _min=nums[0];
       int max_diff = -1;
       for(int i=1;i<nums.size();i++){
        if(nums[i]>_min){
            max_diff = max(max_diff,nums[i]-_min);
        }
        _min = min(_min,nums[i]); 
       }
       return max_diff;
    }
};