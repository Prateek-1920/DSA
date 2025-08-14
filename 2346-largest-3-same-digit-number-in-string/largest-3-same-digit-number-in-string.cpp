class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        int ans = -1;
        int left = 0;
        for(int right = 0;right<n;right++){
            if(num[right]==num[left]){
                if(right-left+1==3){
                    ans = max(ans , num[left]-'0');
                    left = right;
                }
            }
            else{
                left =right;
            }
        }
        if(ans == -1){
            return "";
        }
        
        string temp = to_string(ans) + to_string(ans) + to_string(ans);
        return temp;
    }
};