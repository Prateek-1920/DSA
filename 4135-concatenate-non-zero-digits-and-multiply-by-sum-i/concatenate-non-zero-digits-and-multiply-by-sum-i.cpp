class Solution {
public:
    long long sumAndMultiply(int n) {
        int sum = 0;
        int num = 0;
        long long ans = 0;

        while(n>0){
            int temp = n%10;
            sum = sum + temp;
            n = n/10;
            if(temp==0){
                continue;
            }
            ans = ans + pow(10,num) * temp;
            num++;
        }

        return ans*sum;
    }
};