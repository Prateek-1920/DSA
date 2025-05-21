//code for toposort and cycledetection using bfs
//KAHN'S algorithm

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> toposort(vector<vector<int>>& graph){
    int vertices = graph.size();
    vector<int> indegree(vertices,0);

    //indegree of all nodes
    for(int i=0;i<vertices;i++){
        for(int neighbour : graph[i]){
            indegree[neighbour]++;
        }
    }

    //push nodes of indegree 0 in queue
    queue<int> q;
    for(int i=0;i<vertices;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }

    vector<int> topo;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        topo.push_back(node);

        for(int neighbour :graph[node]){
            indegree[neighbour]--;
            if(indegree[neighbour]==0){
                q.push(neighbour);
            }
        }
    }

    //cycle detetction also
    if(topo.size()!=vertices){
        cout<<"CYCLE DETECTED";
        return{};
    }
    return topo;
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {2},
        {3},
        {0}
    };

    int v = graph.size();
    vector<int> ans = toposort(graph);
    for(int i : ans){
        cout<<i<<" ";
    }
    return 0;
}