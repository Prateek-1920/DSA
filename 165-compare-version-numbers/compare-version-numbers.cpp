class Solution {
public:
    int compareVersion(string version1, string version2) {
        int p1 = 0;
        int p2 = 0;
        int m = version1.length();
        int n = version2.length();

        while(p1<m || p2<n){
            string temp1 = "";
            string temp2 = "";
            while(p1<m && version1[p1]!='.'){
                temp1+=version1[p1];
                p1++;
            }
            if(p1>m){
                temp1 = '0';
            }
            while(p2<n && version2[p2]!='.'){
                temp2+=version2[p2];
                p2++;
            }
            if(p2>n){
                temp2 = '0';
            }
            if(stoi(temp1)<stoi(temp2)){
                return -1;
            }
            else if(stoi(temp1)>stoi(temp2)){
                return 1;
            }
            // if(p1<m){
            //     p1++;
            // }
            // if(p2<n){
            //     p2++;
            // }
            p1++;
            p2++;
        }
        return 0;
    }
};