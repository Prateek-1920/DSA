class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int,int>> q;
        if(grid[0][0]==1|| grid[n-1][n-1]==1)return -1;
        if(n==1)return 1;
        q.push({0,0});
        grid[0][0] = 1;
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                for(auto &it : dir){
                    int newrow = row + it.first;
                    int newcol = col + it.second;

                    if(newrow>=0 && newrow<n && newcol>=0 && newcol <n && grid[newrow][newcol]==0){
                        if(newrow==n-1 && newcol==n-1){
                            return steps+1;
                        }
                        else{
                            grid[newrow][newcol]=1;
                            q.push({newrow,newcol});
                        }
                    }
                }
            }
        }
        return -1;
    }
};
