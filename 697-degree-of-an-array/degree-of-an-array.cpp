class Solution {
private:
    int find(vector<int>&nums, int ele){
        int left = -1;
        int right = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==ele){
                if(left==-1){
                    left = i;
                }
                // else{
                    right = i;
                // }
            }
        }
        return right-left+1;
    }
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> freq;
        int max_freq = 0;
        for(int i : nums){
            freq[i]++;
            max_freq = max(max_freq,freq[i]);
        }
        vector<int> elements;
        for(auto &it : freq){
            if(it.second==max_freq){
                elements.push_back(it.first);
            }
        }

        // int left = -1;
        // int right = 0;
        // for(int i=0;i<n;i++){
        //     if(nums[i]==max_ele){
        //         if(left==-1){
        //             left = i;
        //         }
        //         // else{
        //             right = i;
        //         // }
        //     }
        // }

        int ans = INT_MAX;
        for(int i : elements){
            ans = min(ans,find(nums,i));
        }

        return ans;
    }
};