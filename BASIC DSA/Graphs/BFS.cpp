#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int node,const vector<vector<int>>& graph, vector<bool> &visited){
    queue<int> q;
    visited[node] = true;
    q.push(node);
    cout<<"BFS starting from node "<<node<<endl;

    while(q.empty()==false){
        int current = q.front();
        q.pop();
        cout<<current<<" ";
        for(int neighbour : graph[current]){
            if(visited[neighbour]==false){
                visited[neighbour]=true;
                q.push(neighbour);
            }
        }
    }
}

int main(){
    vector<vector<int>> graphs = {
        {1,2},
        {0,2},
        {2,3},
        {0,3}
    };
    
    int v = graphs.size();
    vector<bool>visited(v,false);
    for(int i=0;i<v;i++){
        if(!visited[i])
        BFS(i,graphs,visited);
    }
    return 0;
}
