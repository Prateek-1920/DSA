class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());

        for(auto s : folder){
            if(ans.empty() || s.substr(0,ans.back().length())!=ans.back() || s[ans.back().length()]!='/'){
                ans.push_back(s);
            }
        }
        return ans;
    }
};


