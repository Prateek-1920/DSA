class Solution {
private:
    void backtrack(int index, int segments, string &s,string &current, vector<string>&ans){
        if(segments==4){
            if(index==s.length()){
                ans.push_back(current.substr(0,current.length()-1));
                return ;
            }
        }
        if(segments>4 || index==s.length()){
            return ;
        }

        for(int i=1;i<=3;i++){
            int segment_end_idx = index+i;
            if(segment_end_idx>s.length()){
                break;
            }
            string substr = s.substr(index,i);
            if((substr.length()>1 && substr[0]=='0') || stoi(substr)>255 ){
                break;
            }
            current+=substr+'.';
            backtrack(segment_end_idx,segments+1,s,current,ans);
            current.resize(current.length()-i-1);
        }

    }
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string str = "";
        backtrack(0,0,s,str,ans);
        return ans;
    }
};