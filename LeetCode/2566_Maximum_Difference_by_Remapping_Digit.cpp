class Solution {
public:
    int minMaxDifference(int num) {
        string maxnum = to_string(num);
        string minnum = to_string(num);

        char maxele;
        char minele;
        for(int i=0;i<maxnum.size();i++){
            if(maxnum[i]!='9'){
                maxele=maxnum[i];
                break;
            }
        }

        for(int i=0;i<maxnum.size();i++){
            if(maxnum[i]!='0'){
                minele=maxnum[i];
                break;
            }
        }

        for(int i=0;i<maxnum.size();i++){
            if(maxnum[i]==maxele){
                maxnum[i]='9';
            }
        }


         for(int i=0;i<minnum.size();i++){
            if(minnum[i]==minele){
                minnum[i]='0';
            }
        }

         

        return stoi(maxnum)-stoi(minnum);
        
    }
};