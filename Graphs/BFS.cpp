#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void BFS(int node,const vector<vector<int>>& graph){
    int vertices = graph.size();
    vector<bool> visited(vertices,false);
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

    BFS(0,graphs);
    return 0;
}
