class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int MOD = 1e9+7;

        vector<vector<pair<int,int>>> graph(n);
        for(auto &it : roads){
            int src = it[0];
            int dest = it[1];
            int time = it[2];
            graph[src].push_back({dest,time});
            graph[dest].push_back({src,time});
        }

        vector<long long> min_time(n,LLONG_MAX);
        vector<long long> ways(n,0);
        priority_queue<pair<long long,int>,vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

        min_time[0] = 0;
        ways[0] = 1;
        pq.push({0,0}); //time, src

        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(time > min_time[node]){
                continue;
            }

            for(auto &it : graph[node]){
                int neighbour = it.first;
                long long newtime = it.second + time;
                if(newtime < min_time[neighbour]){
                    min_time[neighbour] = newtime;
                    ways[neighbour] = ways[node];
                    pq.push({newtime,neighbour});
                }
                else if(newtime==min_time[neighbour]){
                    ways[neighbour] =(ways[node] + ways[neighbour])%MOD;
                }
            }
        }
    return ways[n-1];
    }
};