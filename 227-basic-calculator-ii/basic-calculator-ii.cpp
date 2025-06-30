class Solution {
public:
    int calculate(string s) {
        s+='+';
        stack<int> num;
        char sign = '+';
        long long ans = 0;
        long long curr = 0;

        for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                curr = curr*10+(s[i]-'0');
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                if(sign=='+'){
                    num.push(curr);
                }
                else if(sign=='-'){
                    num.push(-1*curr);
                }
                else if(sign=='*'){
                    int n = num.top();
                    num.pop();
                    num.push(n*curr);
                }
                else if(sign=='/'){
                    int n = num.top();
                    num.pop();
                    num.push(n/curr);
                }
                curr = 0;
                sign = s[i];
            }
        }

        while(!num.empty()){
            ans+=num.top();
            num.pop();
        }
        return ans;

    }
};