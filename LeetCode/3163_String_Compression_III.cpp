
class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int len = 1;
        for(int i=1;i<word.size();i++){
            if(word[i]==word[i-1]){
                len++;
            }
            else{
                int count = len;
                while(count > 9){
                    comp+="9";
                    comp+=word[i-1];
                    count-=9;
                }
                comp += to_string(count)+word[i-1];
                len=1;
            }
        }
        int count = len;
        while(count > 9){
            comp+="9";
            comp+=word.back();
            count-=9;
        }
        comp +=  to_string(count) + word.back();
        return comp;
    }
};

