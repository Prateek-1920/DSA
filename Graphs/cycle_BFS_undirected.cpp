#include<iostream>
#include<vector>
#include<queue>
using namespace std;

bool bfs(int start, vector<vector<int>>&graph, vector<bool>& visited){
    queue<pair<int,int>>q;
    q.push({start,-1});  //node parent
    visited[start]=true;

    while(!q.empty()){
        int node = q.front().first;
        int parent = q.front().second;
        q.pop();

        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                visited[neighbour]=true;
                q.push({neighbour,node});
            }
            else if(neighbour!=parent){
                return true;
            }
        }
    }
    return false;
}

bool hascycle(vector<vector<int>>&graph){
    int v = graph.size();
    vector<bool> visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i]){
            if(bfs(i,graph,visited))return true;
        }
    }
    return false;
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {3},
        {},
        {}
    };

    if(hascycle(graph)) cout<<"CYCLE DETECTED";
    else cout<<"CYCLE NOT DETECTED";

    return 0;
}