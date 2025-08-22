class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int minx = INT_MAX;
        int miny = INT_MAX;
        int maxx = INT_MIN;
        int maxy = INT_MIN;

        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    maxx = max(maxx,j);
                    maxy = max(maxy,i);
                    minx = min(minx,j);
                    miny = min(miny,i);
                }
            }
        }
        
        int height = maxx-minx+1;
        int width = maxy-miny+1;

        return height * width;
    }
};