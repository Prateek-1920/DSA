class Solution {
void dfs(int node, vector<vector<int>>&graph, vector<bool> &visited){
    visited[node]=true;
    for(int neighbour : graph[node]){
        if(!visited[neighbour]){
            dfs(neighbour,graph,visited);
        }
    }
}
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int vertices = rooms.size();
        vector<bool> visited(vertices,false);
        // for(int i=0;i<vertices;i++){
        //     if(!visited[i]){
        //         dfs(i,rooms,visited);
        //     }
        // }

        dfs(0,rooms,visited);
        for(auto i : visited){
            if(i==false){
                return false;
            }
        }
        return true;
    }
};
