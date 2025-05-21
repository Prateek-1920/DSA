class Solution {
private:
    bool dfscycle(int node, vector<vector<int>>& graph, stack<int>& st, vector<int>& visited){
        if(visited[node] == 1) return true;
        if(visited[node] == 2) return false;

        visited[node]=1;
        for(int neighbour : graph[node]){
             if(dfscycle(neighbour,graph,st,visited))return true;
        }
        visited[node]=2;
        st.push(node);
        return false;
    }

    vector<int> toposort(vector<vector<int>>&graph, vector<int>&visited){
        int v = graph.size();
        stack<int> st;
        for(int i=0;i<v;i++){
            if(visited[i]==0){
                if(dfscycle(i,graph,st,visited))return{};
            }
        }

        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<vector<int>> graph(numCourses);
        for(auto &it : prerequisites){
            graph[it[1]].push_back(it[0]);
        }
        return(toposort(graph,visited));
    }
};
