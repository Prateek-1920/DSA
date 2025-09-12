class Solution {
public:
    string sortVowels(string s) {
        int n = s.length();
        vector<char> str(n,'0');
        vector<char> vovels;

        for(int i=0;i<n;i++){
            if(s[i]=='a' ||  s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U'){
                vovels.push_back(s[i]);
            }
            else{
                str[i] = s[i];
            }
        }

    sort(vovels.begin(),vovels.end());
    int idx = 0;
    string ans = "";
    for(int i=0;i<n;i++){
        if(str[i]!='0'){
            ans+=s[i];
        }
        else{
            ans+=vovels[idx];
            idx++;
        }
    }
    return ans;
        
    }
};