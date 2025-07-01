class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        int n = numCourses;
        vector<vector<int>> dist(n, vector<int>(n,INT_MAX));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto &it : prerequisites){
            dist[it[0]][it[1]] = 1;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]<INT_MAX && dist[k][j]<INT_MAX){
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int q = queries.size();
        vector<bool> ans(q,true);
        for(int i=0;i<q;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(dist[a][b]==INT_MAX){
                ans[i] = false;
            }
        }

        return ans;
    }
};