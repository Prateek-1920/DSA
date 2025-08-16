class Solution {
    int dfs(int node, vector<vector<int>>&graph,vector<int>& quiet, vector<int>&ans){
        if(ans[node]!=-1){
            return ans[node];
        }
        ans[node] = node;
        for(int neighbour : graph[node]){
            int cand = dfs(neighbour,graph,quiet,ans);
            if(quiet[cand] < quiet[ans[node]]){
                ans[node] = cand; 
            }
        }
        return ans[node];
    }
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int vertices = quiet.size();
        vector<vector<int>> graph(vertices);
        for(int i=0;i<richer.size();i++){
            int node = richer[i][1];
            int dest = richer[i][0];
            graph[node].push_back(dest);
        }

        vector<int> ans(vertices,-1);

        for(int i=0;i<vertices;i++){
            dfs(i,graph,quiet,ans);
        }
        return ans;
    }
};