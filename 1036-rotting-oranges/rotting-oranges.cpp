// class Solution {
// public:
//     int orangesRotting(vector<vector<int>>& grid) {
//         int rows = grid.size();
//         int cols = grid[0].size();
//         queue<pair<pair<int,int>, int>> rotten;
//         vector<vector<int>> vis(rows,vector<int>(cols));
//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(grid[i][j]==2){
//                     rotten.push({{i,j},0});
//                     vis[i][j]=2;
//                 }
//             }
//         }

//         int time = 0;
//         int drow[] = {-1,0,1,0};
//         int dcol[] = {0,-1,0,1};
//         while(!rotten.empty()){
//             int r = rotten.front().first.first;
//             int c = rotten.front().first.second;
//             int t = rotten.front().second;
//             time = max(time,t);
//             rotten.pop();
//             for(int i=0;i<4;i++){
//                 int nrow = r+drow[i];
//                 int ncol = c+dcol[i];
//                 if(nrow>=0 && nrow<rows &&ncol>=0 && ncol < cols && vis[nrow][ncol] !=2 && grid[nrow][ncol]==1){
//                     rotten.push({{nrow,ncol},t+1});
//                     vis[nrow][ncol] = 2;
//                 }
//             }
//         }

//         for(int i=0;i<rows;i++){
//             for(int j=0;j<cols;j++){
//                 if(vis[i][j] !=2 && grid[i][j]==1){
//                     return -1;
//                 }
//             }
//         }

//         return time;
//     }
// };


class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<pair<int,int>, int>> rotten;
        vector<vector<int>> vis(rows,vector<int>(cols));
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(grid[i][j]==2){
                    rotten.push({{i,j},0});
                    vis[i][j]=2;
                }
            }
        }

        int time = 0;
        vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
        while(!rotten.empty()){
            int x = rotten.front().first.first;
            int y = rotten.front().first.second;
            int t = rotten.front().second;
            time = max(time,t);
            rotten.pop();
            for(auto &it : dir){
                int newx = x+it.first;
                int newy = y+it.second;
                if(newx>=0 && newx<rows && newy>=0 && newy < cols && vis[newx][newy] !=2 && grid[newx][newy]==1){
                    rotten.push({{newx,newy},t+1});
                    vis[newx][newy] = 2;
                }
            }
        }

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(vis[i][j] !=2 && grid[i][j]==1){
                    return -1;
                }
            }
        }

        return time;
    }
};