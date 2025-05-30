class Solution {
private:
    void dfs(int node , vector<int> &graph, vector<int>&dist){
        int d = 0;
        while(node != -1 && dist[node] == -1){
            dist[node] = d;
            d++;
            node = graph[node];
        }
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n,-1);        
        vector<int> dist2(n,-1);
        int count = 0;

        dfs(node1,edges,dist1);
        dfs(node2,edges,dist2);

        int ans = -1;
        int mindist = INT_MAX;
        for(int i=0;i<n;i++){
            if(dist1[i]!=-1 && dist2[i]!=-1){
                int maxdist = max(dist1[i],dist2[i]);
                if(maxdist < mindist){
                    mindist = maxdist;
                    ans = i;
                }
            }
        }
        return ans;
    }
};
