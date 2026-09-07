class Solution {
private:
    void dfs(int node, vector<vector<int>> &graph , vector<bool> &visited){
        visited[node] = true;
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                dfs(neighbour,graph,visited);
            }
        }
    }
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);

        for(auto &edge : invocations){
            int a = edge[0];
            int b = edge[1];
            graph[a].push_back(b);
        }

        vector<bool> sus(n,false);
        dfs(k,graph,sus);

        for(auto &edge : invocations){
            int a = edge[0];
            int b = edge[1];

            if(!sus[a] && sus[b]){
                vector<int> ans;
                for(int i=0;i<n;i++){
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!sus[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};