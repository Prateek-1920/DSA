class Solution {
    int hypt(int len, int width){
        return pow(len,2) + pow(width,2);
    }
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double diag = 0;
        int area = 0;
        for(auto &it : dimensions){
            int len = it[0];
            int width = it[1];
            int new_diag = hypt(len,width);
            if(new_diag >diag){
                area = len*width;
                diag = new_diag;
            }
            else if(new_diag==diag){
                area = max(area,len*width);
            }
        }
        return area;
    }
};