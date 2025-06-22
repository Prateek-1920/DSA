class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int l = s.length();
        int groups = (l+k-1)/k;
        vector<string> ans;
        int group = 0;
        for(int group = 0; group<groups; group++){
            string str = ""; 
            for(int i=0;i<k;i++){
                int idx = i+group*k;
                if(idx<l){
                    str+=s[idx];
                }
                else{
                    str+=fill;
                }
            }
            ans.push_back(str);
        }
        return ans;
    }
};