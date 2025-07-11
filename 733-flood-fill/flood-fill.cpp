class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rows = image.size();
        int cols = image[0].size();
        queue<pair<int,int>> q;

        int originalColor = image[sr][sc];
        if (originalColor == color) return image;

        q.push({sr,sc});
        // visited[sr][sc]=-1;
        image[sr][sc]=color;
        vector<pair<int,int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};

        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(auto &it : dir){
                int newx = x+it.first;
                int newy = y+it.second;
                if(newx>=0 && newx < rows && newy>=0 && newy<cols && originalColor==image[newx][newy]){
                    image[newx][newy] = color;
                    q.push({newx,newy});
                }
            }
        }
        return image;
    }
};