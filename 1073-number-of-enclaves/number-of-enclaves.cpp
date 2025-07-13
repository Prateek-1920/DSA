class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<m;i++){
            if(grid[i][0]==1){
                grid[i][0]=-1;
                q.push({i,0});
            }
            if(grid[i][n-1]==1){
                grid[i][n-1]=-1;
                q.push({i,n-1});
            }
        }

        for(int i=0;i<n;i++){
            if(grid[0][i]==1){
                grid[0][i]=-1;
                q.push({0,i});
            }
            if(grid[m-1][i]==1){
                grid[m-1][i]=-1;
                q.push({m-1,i});
            }
        }

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto &it : dir){
                int newx = x + it.first;
                int newy = y + it.second;
                if(newx>=0 && newx < m && newy>=0 && newy<n && grid[newx][newy]==1){
                    grid[newx][newy] = -1;
                    q.push({newx,newy});
                }
            }
        }

        int count = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    count++;
                }
            }
        }
    return count;
    }
};