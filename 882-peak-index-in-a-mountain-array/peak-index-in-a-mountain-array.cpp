class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int low = 0;
        int high = arr.size()-1;
        int peak = INT_MIN;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]>arr[mid+1]){
                high=mid-1;
            }
            // else if(arr[mid]<arr[mid+1]){

            // }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};