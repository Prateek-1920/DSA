class Solution {
public:
    int twoEggDrop(int n) {
        int ans = 1;
        int times = 1;
        while(ans<n){
            times++;
            ans+=times;
        }
        return times;
    }
};