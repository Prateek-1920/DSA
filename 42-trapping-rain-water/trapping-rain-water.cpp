class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> leftmaxarr(n);
        vector<int> rightmaxarr(n);

        leftmaxarr[0] = height[0];
        for(int i=1;i<n;i++){
            leftmaxarr[i] = max(height[i],leftmaxarr[i-1]);
        }

        rightmaxarr[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
            rightmaxarr[i] = max(height[i],rightmaxarr[i+1]);
        }

        int sum = 0;
        for(int i=0;i<n;i++){
            sum += min(leftmaxarr[i],rightmaxarr[i])-height[i];
        }
        return sum;

        
    }
};