class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<pair<int,int>> dir = {{0,-1},{0,1},{1,0},{-1,0}};

        deque<pair<int,int>> q;

        vector<vector<int>> dist(m, vector<int>(n,99999));
        dist[0][0] = 0;

        q.push_front({0,0});

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop_front();
            for(auto &it : dir){
                int newx = x+it.first;
                int newy = y+it.second;
                if(newx>=0 && newx<m && newy>=0 && newy<n){
                    int cost = dist[x][y] + grid[newx][newy];
                    if(cost<dist[newx][newy]){
                        dist[newx][newy] = cost;
                        if(grid[newx][newy]==0)q.push_front({newx,newy});
                        else q.push_back({newx,newy});
                    }
                }
            }
        }
        return dist[m-1][n-1];

    }
};