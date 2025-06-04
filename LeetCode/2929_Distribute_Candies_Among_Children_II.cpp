class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long count = 0;
        for(int a=0;a<=limit;a++){
            int target = n-a;   // a+b+c = n so b+c = n-a => b+c = target
            int low = max(0,target-limit);
            int high = min(target,limit);
            if(low<=high){
                count+=high-low+1;
            }
        }
        return count;
    }
};