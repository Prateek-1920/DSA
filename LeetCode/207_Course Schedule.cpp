class Solution {
private:
    bool hascycle(const vector<vector<int>>& graph,vector<int>& visited,int course){
        if(visited[course]==1){
            return true;
        }
        if(visited[course]==2){
            return false;
        }

        visited[course]=1;
        for(int neighbour : graph[course]){
            if(hascycle(graph,visited,neighbour)) return true;
        }
        visited[course] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto &it : prerequisites){
            graph[it[0]].push_back(it[1]);
        }

        vector<int> visited(numCourses,0);
        for(int i=0;i<numCourses;i++){
            if(visited[i]==0){
                if(hascycle(graph,visited,i)){
                    return false;
                }
            }
        }
        return true;
    }
};
