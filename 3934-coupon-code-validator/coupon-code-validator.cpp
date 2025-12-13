class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        unordered_map<string,int> s = {{"electronics",1}, {"grocery",2},{"pharmacy",3},{"restaurant",4}};
        vector<pair<int,string>> temp;

        for(int i=0;i<n;i++){
            bool valid = true;
            for(char c : code[i]){
                if(!(isalnum(c) || c=='_')){
                    valid = false;
                    break;
                }
            }
            if(!code[i].empty() && valid && s.find(businessLine[i])!=s.end() && isActive[i]){
                temp.push_back({s[businessLine[i]],code[i]});
            }
        }

        sort(temp.begin(),temp.end());
        vector<string> ans;
        for(auto &it : temp){
            ans.push_back(it.second);
        }        
        return ans;
    }
};