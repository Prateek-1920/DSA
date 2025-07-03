class Solution {
public:
    char kthCharacter(int k) {
        string org = "a";
        while(org.length()<k){
            string gen = "";
            for(char c : org){
                if(c=='z'){
                    gen+='a';
                }
                else{
                    gen+= (char)(int(c)+1);
                }
            }
            org+=gen;
        }
        return org[k-1];
    }
};