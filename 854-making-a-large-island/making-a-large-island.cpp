class Solution {
private:
    int dfs(int x, int y, int m, int n, vector<vector<int>> &grid, int id){
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        int size = 1;
        grid[x][y] = id;
        for(auto &it : dir){
            int newx = x+ it.first;
            int newy = y +it.second;
            if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]==1){
                size+=dfs(newx,newy,m,n,grid,id);
            }
        }
        return size;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int,int> island;
        int m = grid.size();
        int n = grid[0].size();
        int id = 2;
        int maxislands = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size = dfs(i,j,m,n,grid, id);
                    island[id] = size;
                    maxislands = max(maxislands,size);
                    id++;
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    unordered_set<int> neighbours;
                    for(auto &it : dir){
                        int x = i+ it.first;
                        int y = j + it.second;
                        if(x>=0 && x<m && y>=0 && y<m && grid[x][y]>1){
                            neighbours.insert(grid[x][y]);
                        }
                    }
                    int size = 1;
                    for(int it : neighbours){
                        size+=island[it];
                    }
                    maxislands = max(maxislands,size);
                }
            }
        }
        return maxislands == 0 ? m * n : maxislands;
    }
};