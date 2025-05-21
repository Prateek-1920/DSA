class Solution {
private:
    void dfs(int node, int dest, vector<vector<int>>&graph, vector<int>&path, vector<vector<int>>&allpaths){
        path.push_back(node);
        if(node==dest){
            allpaths.push_back(path);
        }
        else{
            for(int neighbour : graph[node]){
                dfs(neighbour,dest,graph,path,allpaths);
            }
        }
        path.pop_back();

    }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>allpaths;
        vector<int>path;
        int dest = graph.size()-1;
        dfs(0,dest,graph,path,allpaths);
        return allpaths;

    }
};
