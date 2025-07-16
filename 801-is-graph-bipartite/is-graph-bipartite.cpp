class Solution {
    private:
    bool bfs(vector<vector<int>>& graph, int start, vector<int>& color){
        queue<int> q;
        q.push(start);
        color[start]=1;

        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int neighbour : graph[curr]){
                if(color[neighbour]==-1){
                    color[neighbour] = (color[curr]==1?0:1);
                    q.push(neighbour);
                }
                else if(color[neighbour] == color[curr]){
                    return false;
                }
            }
        }
        return true;
    }

    bool dfs(vector<vector<int>>&graph, vector<int>&visited, int node, int c){
        visited[node] = c;
        for(int neighbour : graph[node]){
            if(visited[neighbour]==-1){
                if(!dfs(graph,visited,neighbour,1-c))return false;
            }
            else if(visited[neighbour]==c){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> color(v,-1);
        for(int i=0;i<v;i++){
            if(color[i]==-1){
                // if(bfs(graph,i,color)==false){
                if(dfs(graph,color,i,0)==false){
                    return false;
                }
            }
        }
        return true;
    }
};