class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int l1 = word1.length();
        int l2 = word2.length();
        if(l1!=l2){
            return false;
        }

        unordered_set<char> s1;
        unordered_set<char> s2;

        for(int i=0;i<l1;i++){
            s1.insert(word1[i]);
            s2.insert(word2[i]);
        }
        if(s1!=s2){
            return false;
        }
        
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;

        for(int i=0;i<l1;i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        vector<int> v1;
        vector<int> v2;

        for(auto &it : mp1){
            v1.push_back(it.second);
        }
        for(auto &it : mp2){
            v2.push_back(it.second);
        }

        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2)return false;
        return true;


    }
};
