class Solution {
// private:
//     bool dfs(int u, int v, vector<vector<int>> &graph, vector<bool> &visited){
//         if(u==v){
//             return true;
//         }
//         visited[u] = true;
//         for(int neighbour : graph[u]){
//             if(!visited[neighbour])
//             {
//                 if(neighbour==v){
//                     return true;
//                 }
//                 else if(dfs(neighbour,v,graph,visited)==true){
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        // vector<vector<int>> graph(n);
        // vector<bool> ans(queries.size(),false);

        // for(int i=1;i<nums.size();i++){
        //     int a = nums[i];
        //     int b = nums[i-1];
        //     if(abs(a-b)<=maxDiff){
        //         graph[i].push_back(i-1);
        //         graph[i-1].push_back(i);
        //     }
        // }

        // int i=0;
        // for(auto &it : queries){
        //     vector<bool> visited(n,false);
        //     int u = it[0];
        //     int v = it[1];
        //     bool temp = dfs(u,v,graph,visited);
        //     ans[i] = temp;
        //     i++;
        // }

        // return ans;

        vector<int> component(n);
        vector<bool> ans;
        component[0] = 0;
        int comp = 0;

        for(int i=1;i<nums.size();i++){
            if(abs(nums[i]-nums[i-1])>maxDiff){
                comp++;
            }
            component[i] = comp;
        }

        for(auto &it : queries){
            int a = it[0];
            int b = it[1];
            if(component[a]==component[b]){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
    return ans;
    }
};