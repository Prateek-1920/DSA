class Solution {
private:
    void paths(int x, int y, vector<vector<int>>&grid, int& count, int can_visit, int visited_count){
        if(grid[x][y]==2){
            if(visited_count == can_visit){
            count++;
            }
            return;
        }
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        for(auto &it : dir){
            int newx = x + it.first;
            int newy = y + it.second;
            if(newx>=0 && newx< grid.size() && newy>=0 && newy<grid[0].size() && grid[newx][newy]!=-1){
                if (grid[newx][newy] == 0) { // Only mark empty squares as visited (3)
                    int temp = grid[newx][newy];
                    grid[newx][newy]=3; // Mark as visited
                    paths(newx, newy, grid, count, can_visit, visited_count+1);
                    grid[newx][newy] = temp; // Backtrack
                } else if (grid[newx][newy] == 2) { // If it's the end, just go there
                    paths(newx, newy, grid, count, can_visit, visited_count + 1);
                }
            }
        }
    }
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int count = 0;
        int can_visit = 0;
        int x=-1;
        int y=-1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1){
                    x = i;
                    y = j;
                }
                if(grid[i][j]==0 || grid[i][j]==1 || grid[i][j]==2){
                    can_visit++;
                }
            }
        }
        if(x==-1 || y==-1){
            return 0;
        }
        int temp = grid[x][y]; // Store original value
        grid[x][y]=3;
        paths(x,y,grid,count,can_visit,1);
        grid[x][y]=temp;
        return count;
    }
};