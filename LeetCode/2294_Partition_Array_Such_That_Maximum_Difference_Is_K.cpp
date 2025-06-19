class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int maxnum = INT_MIN;
        int minnum = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>maxnum){
                maxnum =nums[i];
            }
            if(nums[i]<minnum){
                minnum = nums[i];
            }
            if(maxnum-minnum>k){
                count++;
                minnum = maxnum;
                maxnum = minnum;
            }
        }
        if(maxnum-minnum<=k){
            count++;
        }
        return count;
    }
};



// class Solution {
// public:
//     int partitionArray(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());
//         int count = 1;
//         vector<int> temp;
//         for(int i=0;i<nums.size();i++){
//             temp.push_back(nums[i]);
//             if(*max_element(temp.begin(),temp.end()) - *min_element(temp.begin(),temp.end())>k){
//                 count = count+1;
//                 temp = {};
//                 temp.push_back(nums[i]);
//             }
//         }
//         return count;
//     }
// };