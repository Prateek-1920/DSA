#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int parent, vector<vector<int>> &graph, vector<bool>&visited){
    visited[node]=true;
    for(int neighbour : graph[node]){
        if(!visited[neighbour]){
            if(dfs(neighbour,node,graph,visited)) return true;
        }
        else if(neighbour!=parent){
            return true;
        }
    }
    return false;
}

bool hascycle(vector<vector<int>> &graph){
    int vertices = graph.size();
    vector<bool> visited(vertices,false);
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            if(dfs(i,-1,graph,visited))return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>>graph = {
        {1,2},
        {3},
        {},
        {}
    };

    if(hascycle(graph)){
        cout<<"CYCLE DETECTED";
    }
    else{
        cout<<"NO CYCLE";
    }
    return 0;
}