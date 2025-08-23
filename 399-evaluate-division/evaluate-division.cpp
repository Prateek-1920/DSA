class Solution {
    double dfs(int node, double value, int dest, vector<vector<pair<int,double>>>&graph, vector<bool>&visited){
        if(node==dest){
            return value;
        }
        visited[node]=true;
        for(auto &it : graph[node]){
            int neighbour = it.first;
            double val = it.second;
            if(!visited[neighbour]){
                double res =  dfs(neighbour,value*val,dest,graph,visited);
                if(res!=-1){
                    return res;
                }
            }
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,int> id;
        int idx = 0;
        for (auto &eq : equations) {
            if (!id.count(eq[0])) id[eq[0]] = idx++;
            if (!id.count(eq[1])) id[eq[1]] = idx++;
        }

        int n = id.size();
        vector<vector<pair<int,double>>> graph(n);

        for(int i=0;i<equations.size();i++){
            int src = id[equations[i][0]];
            int dest = id[equations[i][1]];
            double val = values[i];
            graph[src].push_back({dest,val});
            graph[dest].push_back({src,1/val});
        }

        vector<double> ans;
        for(auto & it : queries){
            vector<bool> visited(n,false);
          
            if(!id.count(it[0]) || !id.count(it[1])){
                ans.push_back(-1);
            }
            else{
                double src = id[it[0]];
                double dest = id[it[1]];
                double a = dfs(src,1.00000,dest,graph,visited);
                ans.push_back(a);
            }
        }
        return ans;

    }
};