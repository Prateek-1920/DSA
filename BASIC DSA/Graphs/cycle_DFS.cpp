#include<iostream>
#include<vector>
using namespace std;

bool hascycle(int node, vector<vector<int>>& graph, vector<int> &visited){
    if(visited[node]==1){
        return true;
    }
    if(visited[node]==2){
        return false;
    }

    visited[node]=1;
    for(int neighbour:graph[node]){
        if(hascycle(neighbour,graph,visited)==true) return true;
    }
    visited[node]=2;
    return false;
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {2},
        {3},
        {}
    };

    int vertices = graph.size();
    vector<int> visited(vertices,0);
    for(int i=0;i<vertices;i++){
        if(visited[i]==0){
            if(hascycle(i,graph,visited)){
                cout<<"Cycle detected !";
                break;
            }
            cout<<"Cycle not detected";
        }
    }
    return 0;
}