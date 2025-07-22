class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        vector<int> min_steps(n,INT_MAX);
        min_steps[src] = 0;

        for(auto &i : flights){
            int src = i[0];
            int dest = i[1];
            int cost = i[2];
            graph[src].push_back({dest,cost});
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0,src,0}); //IMPORTANT
        while(!pq.empty()){
            int node = pq.top()[1];
            int cost = pq.top()[0];
            int steps = pq.top()[2];
            pq.pop();

            if(node==dst){
                return cost;
            }
            if(steps>k || steps > min_steps[node]){
                continue;
            }
            min_steps[node] = steps;
          
            for(auto &it : graph[node]){
                int neighbour = it.first;
                int newcost = it.second + cost;
                pq.push({newcost,neighbour,steps+1});
            }
        }
        return -1;

    }
};