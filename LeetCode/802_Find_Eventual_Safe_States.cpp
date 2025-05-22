class Solution {
private:
    bool hascycle(int node, vector<vector<int>>&graph, vector<int>&visited){
        if(visited[node]==1)return true;
        if(visited[node]==2)return false;

        visited[node]=1;
        for(int neighbour : graph[node]){
            if(hascycle(neighbour,graph,visited))return true;
        }
        visited[node]=2;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int vertices = graph.size();
        vector<int> visited(vertices,0);
        vector<int> ans;
        for(int i=0;i<vertices;i++){
            if(hascycle(i,graph,visited))continue;
            else{
                ans.push_back(i);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
