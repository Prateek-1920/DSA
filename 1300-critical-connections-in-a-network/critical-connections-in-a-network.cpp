class Solution {
private:
    int timer = 0;
    void dfs(int node, int parent, vector<vector<int>>&graph, vector<bool>&visited, vector<int>&time, vector<int> &low, vector<vector<int>>&bridges){
        visited[node] = true;
        time[node] = low[node] = timer;
        timer++;
        for(int neighbour : graph[node]){
            if(neighbour == parent){
                continue;
            }
            if(!visited[neighbour]){
                dfs(neighbour, node,graph,visited,time,low,bridges);
                low[node] = min(low[node],low[neighbour]);
                if(low[neighbour]>time[node]){
                    bridges.push_back({node,neighbour});
                }
            }
            else{
                low[node] = min(low[node],time[neighbour]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        vector<bool> visited(n,false);
        vector<int> time(n);
        vector<int> low(n);
        vector<vector<int>> bridges;

        for(auto &it : connections){
            int src = it[0];
            int dest = it[1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }

        dfs(0,-1,graph,visited,time,low,bridges);
        return bridges;
    }
};