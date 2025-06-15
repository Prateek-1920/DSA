class Solution {
public:
    int maxDiff(int num) {
        string maxnum = to_string(num);
        char first = maxnum[0];
        if(first=='9' && maxnum.length()>1){
            for(int i=1;i<maxnum.length();i++){
                if(maxnum[i]!='9'){
                    first=maxnum[i];
                    break;
                }
            }
        }

        for(int i=0;i<maxnum.length();i++){
            if(maxnum[i]==first){
                maxnum[i]='9';
            }
        }


        string minnum = to_string(num);
        first = minnum[0];
        char target ='0';
        char replacement ='0';

        if(first!='1'){
            target = first;
            replacement = '1';
        }
        else{
            for(int i=1;i<minnum.length();i++){
                if(minnum[i]!='1' && minnum[i]!='0'){
                    target = minnum[i];
                    replacement='0';
                    break;
                }
            }
        }


        if(target!=0){
            for (char& c : minnum) {
                if (c == target) c = replacement;
            }
        }

        return stoi(maxnum)-stoi(minnum);


    }
};