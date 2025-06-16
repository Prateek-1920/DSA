class Solution {
private:
    bool recurse(int index , string s, int current_sum, int n){
        if(index==s.length()){
            return current_sum==n;
        }

        for(int end=index+1;end<=s.length();end++){
            string sub = s.substr(index,end-index);
            int num = stoi(sub);
            if(recurse(end,s,current_sum+num,n)){
                return true;
            }
        }
        return false;
    }
public:
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i=1;i<=n;i++){
            if(recurse(0,to_string(i*i),0,i)){
                ans+=i*i;
            }
        }
        return ans;
    }
};