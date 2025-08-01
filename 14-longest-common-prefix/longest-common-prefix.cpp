class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()<=1){
            return strs[0];
        }
        string res = "";
        string first = strs[0];
        for(int i=1;i<strs.size();i++){
            string temp = strs[i];
            if(temp[0]==first[0]){
                int j = 0;
                string newres = "";
                while(j<temp.length() && j<first.length() && temp[j]==first[j]){
                    newres+=temp[j];
                    j++;
                }
                if(res==""){
                    res = newres;
                }
                else{
                    res = newres.length()<res.length() ? newres : res;
                }
            }
            else{
                return "";
            }
        }
        return res;
    }
};