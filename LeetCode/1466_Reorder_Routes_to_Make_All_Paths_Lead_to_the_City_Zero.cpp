class Solution {
private:
    void dfs(int node, vector<vector<int>>&graph, vector<bool>&visited, set<pair<int,int>>&set, int &count){
        visited[node]=true;
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                if(set.find({node,neighbour})!=set.end()){
                    count++;
                }
                dfs(neighbour,graph,visited,set,count);
            }
        }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        // int v = connections.size();
        vector<vector<int>> undirectedgraph(n);
        for(auto &it : connections){
            undirectedgraph[it[0]].push_back(it[1]);
            undirectedgraph[it[1]].push_back(it[0]);
        }

        set<pair<int,int>> set;
        for(auto &it : connections){
            set.insert({it[0],it[1]});
        }

        int count = 0;
        vector<bool> visited(n,false);
        dfs(0,undirectedgraph,visited,set,count);

        return count;

    }
};
