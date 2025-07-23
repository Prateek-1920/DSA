class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,false));
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        pq.push({grid[0][0],0,0}); //time,x,y;
        visited[0][0] = true;

        while(!pq.empty()){
            int time = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();

            if(x==m-1 && y==n-1){
                return time;
            }

            for(auto &it : dir){
                int newx = x + it.first;
                int newy = y + it.second;
                if(newx>=0 && newx<m && newy>=0 && newy<n && !visited[newx][newy]){
                    visited[newx][newy] = true;
                    pq.push({max(time,grid[newx][newy]),newx,newy});
                }
            }
        }
        return -1;
    }
};