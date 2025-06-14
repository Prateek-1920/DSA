class Solution {
private:
    void recurse(string current, vector<string>&ans,int n, int opencount, int closecount){
        if(opencount==n && closecount==n){
            ans.push_back(current);
            return;
        }
        current+=('(');
        if(opencount<n){
            recurse(current,ans,n,opencount+1,closecount);
        }
        current.pop_back();
        current+=(')');
        if(closecount<opencount){
            recurse(current,ans,n,opencount,closecount+1);
        }
        current.pop_back();
    }
public:
    vector<string> generateParenthesis(int n) {
        int index = 0;
        vector<string> ans;
        recurse("",ans,n,0,0);
        return ans;
    }
};