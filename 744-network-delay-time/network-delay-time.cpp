class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        vector<int> min_time(n+1,INT_MAX);
        min_time[k] = 0;

        for(auto &it : times){
            graph[it[0]].push_back({it[1],it[2]});
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});

        while(!pq.empty()){
            int node = pq.top().second;
            int curr_time = pq.top().first;
            pq.pop();
            if(curr_time>min_time[node]){
                continue;
            }

            for(auto &it: graph[node]){
                int newnode = it.first;
                int time = it.second;
                int total_time = time+curr_time;
                if(total_time < min_time[newnode]){
                    min_time[newnode] = total_time;
                    pq.push({total_time,newnode});
                }
            }
        }

        int max_delay = 0; 
        for(int i = 1; i <= n; ++i){ 
            if(min_time[i] == INT_MAX){ 
            return -1;
            }
            max_delay = std::max(max_delay, min_time[i]); 
        }
        return max_delay;
    }
};