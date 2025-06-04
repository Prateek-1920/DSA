class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1){
            return word;
        }
        vector<int> v;
        char ch = *max_element(word.begin(),word.end());
        int n = word.size();
        int size = n-numFriends+1;
        string ans = "";

        for(int i=0;i<n;i++){
            if(word[i]==ch){
                v.push_back(i);
            }
        }

        for(auto i : v){
            string str = (size<=n-i) ? word.substr(i,size) : word.substr(i);
            ans = max(ans,str);
        }
        return ans;
    }
};