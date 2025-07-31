class Solution {
private:
    void components(int node, vector<vector<int>>&graph, vector<int>&neighbours){
        int count =0;
        for(int neighbour : graph[node]){
            count++;
        }
        neighbours[node]=count;
    }
public:
    int findCenter(vector<vector<int>>& edges){
        int n = edges.size()+1;
        vector<vector<int>> graph(n+1);
        for(auto &it : edges){
            int src = it[0];
            int dest = it[1];
            graph[src].push_back(dest);
            graph[dest].push_back(src);
        }
        vector<int> neighbours(n+1,0);
        for(int i = 1;i<=n;i++){
            components(i,graph,neighbours);
        }
        int node = 0;
        int comp = INT_MIN;
        for(int i=1;i<=n;i++){
            if(neighbours[i]>comp){
                comp =neighbours[i];
                node = i;
            }
        }
        return node;
    }
};


// class Solution {

// public:
//     int findCenter(vector<vector<int>>& edges){
//         unordered_map<int,int>freq;
//         for(auto &it : edges){
//             int src = it[0];
//             int dest = it[1];
//             freq[src]++;
//             if(freq[src]>1){
//                 return src;
//             }
//             freq[dest]++;
//             if(freq[dest]>1){
//                 return dest;
//             }
//         }
//         return -1;
//     }
// };