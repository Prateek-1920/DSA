class Solution {
private: 
    void dfs(int node,vector<vector<int>>&graph,vector<bool>&visited){
        visited[node] = true;
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                dfs(neighbour,graph,visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int vertices = isConnected.size();
        vector<vector<int>> graph(vertices);
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                if(isConnected[i][j]==1 && i!=j){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int ans=0;
        vector<bool> visited(vertices,false);
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                ans++;
            }
        }
        return ans;
    }
};