class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    grid[i][j]==0;

                    while(!q.empty()){
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        for(auto &it : dir){
                            int newx = x+it.first;
                            int newy = y+it.second;
                            if(newx>=0 && newx<m && newy>=0 && newy<n && grid[newx][newy]=='1'){
                                q.push({newx,newy});
                                grid[newx][newy]='0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};
