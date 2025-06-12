class Solution {
private:
    int intersect(vector<int>&a, vector<int>&b){
        int count = 0;
        unordered_set<int> seta;
        unordered_set<int> setb;
        for(auto i : a){
            seta.insert(i);
        }
        for(auto i : b){
            setb.insert(i);
        }

        for(auto i : seta){
            if(setb.find(i)!=setb.end()){
                count++;
            }
        }
        return count;
    }

    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited){
        visited[node]=true;
        for(int neighbour : graph[node]){
            if(!visited[neighbour]){
                dfs(neighbour,graph,visited);
            }
        }
    }

    int connected_comp(vector<vector<int>> &graph){
        int comp = 0;
        vector<bool> visited(graph.size(),false);
        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                dfs(i,graph,visited);
                comp++;
            }
        }
        return comp;
    }


public:
    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int vertices = properties.size();
        vector<vector<int>> graph(vertices);
        vector<unordered_set<int>> set(vertices);
        for(int i=0;i<vertices;i++){
            for(int it : properties[i]){
                set[i].insert(it);
            }
        }

        for(int i=0;i<vertices;i++){
            for(int j=i+1;j<vertices;j++){
                int common = 0;
                for(auto &it : set[j]){
                    if(set[i].find(it)!=set[i].end()){
                        common++;
                        if(common>=k)break;
                    }
                }
                if(common>=k){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }

        int ans = connected_comp(graph);
        return ans;
        // return connected_comp(graph);
        
    }
};