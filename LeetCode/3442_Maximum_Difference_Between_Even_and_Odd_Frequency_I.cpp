class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char,int> freq;
        for(int i=0;i<s.length();i++){
            freq[s[i]]++;
        }

        int odd = INT_MIN;
        int even = INT_MAX;

        for(auto &it : freq){
            int count = it.second;
            if(count%2==0){
                if(count<even){even=count;}
            }
            else{
                if(count>odd){odd=count;}
            }
        }
        cout<<odd<<endl;
        cout<<even<<endl;

        return odd-even;
    }
};