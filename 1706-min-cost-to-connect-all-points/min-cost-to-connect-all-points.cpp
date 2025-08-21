class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> visited(n,false);
        vector<int> mindist(n,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;

        pq.push({0,0});
        int ans = 0;
        int count = 0;

        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int cost = it.first;

            if(visited[node]==true){
                continue;
            }

            visited[node]=true;
            ans+=cost;
            count++;

            for(int i=0;i<n;i++){
                if(!visited[i]){
                    int dist = abs(points[node][0] - points[i][0]) + abs(points[node][1] - points[i][1]);
                    if(dist < mindist[i]){
                        mindist[i] = dist;
                        pq.push({dist,i});
                    }
                }
            }
        }
    return ans;
    }
};