class Solution {
private:
    void dfs(int node, vector<vector<int>> &graph, vector<bool> &visited){
        visited[node]=true;
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                dfs(neighbour,graph,visited);
            }
        }
    }
public:
    int removeStones(vector<vector<int>>& stones) {
        int vertices = stones.size();
        vector<vector<int>> graph(vertices);
        for(int i=0;i<vertices;i++){
            for(int j=i+1;j<vertices;j++){
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1]){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int conn_comp = 0;
        vector<bool> visited(vertices,false);
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                conn_comp++;
                dfs(i,graph,visited);
            }
        }
        return vertices-conn_comp;
    }
};