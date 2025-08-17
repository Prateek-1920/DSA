class Solution {
public:
    string convert(string s, int numrows) {
        if(numrows==1 || s.size()<=numrows){
            return s;
        }

        vector<string> matrix(numrows);
        int i=0,n=s.size(),index=0;
        bool dir = true;

        while(i<n){
            matrix[index].push_back(s[i]);
            if(index==numrows-1)dir = false;
            if(index==0)dir = true;
            if(dir)index++;
            else index--;
            i++;
        }

        string ans = "";
        for(auto &c : matrix){
            ans+=c;
        }
        return ans;
    }
};