class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0)); //0=unguarded 1=marked 2=guard 3=wall
        for(int i=0;i<guards.size();i++){
            int x = guards[i][0];
            int y = guards[i][1];
            grid[x][y]=2;
        }
        for(int i=0;i<walls.size();i++){
            int x = walls[i][0];
            int y = walls[i][1];
            grid[x][y]=3;      
        } 

        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        for(auto &it : guards){
            int x = it[0];
            int y = it[1];
            for(auto &j : dir){
                int newx = x + j.first;
                int newy = y + j.second;
                while(newx>=0 && newy>=0 && newx<m && newy<n && grid[newx][newy]!=2 && grid[newx][newy]!=3){
                    grid[newx][newy] = 1;
                    newx+=j.first;
                    newy+=j.second;
                }
            }
        }

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};