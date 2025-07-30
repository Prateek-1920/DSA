class Solution {
private:
    int binsearch(int idx, int k, vector<int>&nums, vector<long long>&prefix){
        long target = nums[idx];
        int low = 0;
        int high = idx;
        int bestidx = idx;
        while(low<=high){
            int mid = low + (high-low)/2;
            long long maxsum = (idx-mid+1) * target;
            long long windowsum = prefix[idx] - (mid > 0 ? prefix[mid - 1] : 0);
            long long targetsum = maxsum - windowsum;
            if(targetsum > k){
                low = mid+1;
            }
            else{
                bestidx = mid;
                high = mid-1;
            }
        }
        return idx-bestidx+1;
    }
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i=1;i<n;i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int res = 0;

        for(int i=0;i<n;i++){
            res = max(res,binsearch(i,k,nums,prefix));
        }
        return res;
    }
};