class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> min_diff(m, vector<int>(n,INT_MAX));
        min_diff[0][0]=0;

        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q ;  
        q.push({0,{0,0}});
        vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
        while(!q.empty()){
            int curr_cost = q.top().first;
            int x = q.top().second.first;
            int y = q.top().second.second;
            q.pop();

            if(curr_cost > min_diff[x][y]){
                continue;
            }
            for(auto &it : dir){
                int newx = x+it.first;
                int newy = y+it.second;
                if(newx>=0 && newx<heights.size() && newy>=0 && newy<heights[0].size()){
                    int cost = abs(heights[newx][newy]-heights[x][y]);
                    int new_cost = max(cost,curr_cost);
                    if(new_cost < min_diff[newx][newy]){
                        min_diff[newx][newy]=new_cost;
                        q.push({new_cost,{newx,newy}});
                    }
                }
            }
        }
        return min_diff[m-1][n-1];
    }
};