class Solution {
public:
    bool isValid(string word) {
        int n = word.length();
        if(n<3)return false;

        // int charcount = 0;
        bool vowelflag = false;
        bool consflag = false;
        unordered_set<char> vowels = {'a','e','i','o','u'};
        for(int i=0;i<n;i++){
            char c = isalpha(word[i]) ? tolower(word[i]) : word[i];

            if(!isalpha(c) && !isdigit(c)){return false;}

            if(isalpha(c)){
                // charcount++;
                if(vowels.find(c)!=vowels.end()){
                    vowelflag=true;
                }
                else{
                    consflag = true;
                }
            } 
        }
        // return (charcount>=3 && vowelflag && consflag);
        return (vowelflag && consflag);
    }
};