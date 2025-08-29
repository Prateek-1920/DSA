class Solution {
public:
    long long flowerGame(int n, int m) {
        long long ans = 0;
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if((i+j)%2!=0){
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        long odd_m = (m+1)/2;
        long odd_n = (n+1)/2;
        long even_m = m/2;
        long even_n = n/2;

        ans = odd_m*even_n + even_m*odd_n;
        return ans;
    }
};