#include<iostream>
#include<stack>
#include<vector>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, stack<int>& st){
    visited[node]=true;
    for(int neighbour : graph[node]){
        if(!visited[neighbour]){
            dfs(neighbour,graph,visited,st);
        }
    }
    st.push(node);
}

void toposort(vector<vector<int>>& graph){
    int vertices = graph.size();
    vector<bool> visited(vertices,false);
    stack<int> st;
    for(int i=0;i<vertices;i++){
        if(!visited[i]){
            dfs(i,graph,visited,st);
        }
    }

    vector<int> result;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}

int main(){
    vector<vector<int>> graph = {
        {1,2},
        {2,0},
        {1,3},
        {0,1}
    };

    int v = graph.size();
    toposort(graph);
    return 0;
}