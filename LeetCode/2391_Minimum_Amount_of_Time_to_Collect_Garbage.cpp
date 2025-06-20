class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int lastG=-1, lastP=-1, lastM=-1;
        for(int i=0;i<garbage.size();i++){
            for(auto c : garbage[i]){
                if(c=='M'){
                    lastM = i;
                }
                if(c=='P'){
                    lastP = i;
                }
                if(c=='G'){
                    lastG = i;
                }
            }
        }

        int glasstime = 0;
        int metaltime = 0;
        int papertime = 0;
        if(lastG!=-1){
            for(int i=0;i<=lastG;i++){
                for(auto c : garbage[i]){
                    if(c=='G'){
                        glasstime++;
                    }
                }
                if(i>0){
                    glasstime+=travel[i-1];
                }
            }
        }
        if(lastM!=-1){
            for(int i=0;i<=lastM;i++){
                for(auto c : garbage[i]){
                    if(c=='M'){
                        metaltime++;
                    }
                }
                if(i>0){
                    metaltime+=travel[i-1];
                }
            }
        }
        if(lastP!=-1){
            for(int i=0;i<=lastP;i++){
                for(auto c : garbage[i]){
                    if(c=='P'){
                        papertime++;
                    }
                }
                if(i>0){
                    papertime+=travel[i-1];
                }
            }
        }
        return glasstime+papertime+metaltime;
    }
};