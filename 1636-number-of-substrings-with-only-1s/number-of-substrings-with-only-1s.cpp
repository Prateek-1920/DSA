class Solution {
public:
    int numSub(string s) {
        long long ans = 0;
        int left = 0;
        int MOD = 1e9 + 7;
        for(int right=0;right<s.length();right++){
            if(s[right]=='1'){
                left = right;
                while(right<s.length() && s[right]!='0'){
                    right++;
                }
                long long n = right-left;
                ans  = (ans + (n*(n+1)/2)%MOD)%MOD;
            }
            left = right;
        }
        return ans;
    }
};