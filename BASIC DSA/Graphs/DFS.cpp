#include<iostream>
#include<vector>
using namespace std;

void DFS(int node, const vector<vector<int>>& graph, vector<bool>& visited){
    visited[node] = true;
    cout<<node<<" ";
    for(int neighbour : graph[node]){
        if(visited[neighbour]==false){
            DFS(neighbour,graph,visited);
        }
    }
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {0,3},
        {1,3},
        {0,2}
    };

    int vertices = graph.size();
    vector<bool> visited(vertices,false);
    cout<<"DFS Traversal: "<<endl;
    for (int i = 0; i < vertices; ++i) {
        if (!visited[i]) {
            DFS(i, graph, visited);
        }
    }    
    return 0;    
}

