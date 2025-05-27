class Solution {
private:
    int dfs(int i, int j, vector<vector<int>>&grid){
        int area = 1;
        grid[i][j]=0;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int m = grid.size();
        int n = grid[0].size();

        for(auto &it : dir){
            int newx = i+it.first;
            int newy = j+it.second;
            if(newx>=0 && newx <m && newy>=0 && newy<n && grid[newx][newy]==1){
                area+=dfs(newx,newy,grid);
            }
        }
        return area;
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    int area = dfs(i,j,grid);
                    ans = max(area,ans);
                }
            }
        }
        return ans;
    }
};
