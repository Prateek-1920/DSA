class Solution {
public:
    vector<int> parent;
    vector<int> size;

    int find(int x){
        if(parent[x]!=x){
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }

    void union_set(int a, int b){
        int pa =  find(a);
        int pb = find(b);
        if(pa!=pb){
            parent[pa] = find(pb);
            size[pb] += size[pa];
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);
        unordered_map<int,int> edgecount;

        for(int i=0;i<n;i++){
            parent[i]=i;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            union_set(u,v);
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int root = find(u);
            edgecount[root]++;
        }

        unordered_map<int,int> nodecount;
        for(int i=0;i<n;i++){
            int root = find(i);
            nodecount[root]++;
        }

        int result = 0;
        for(auto &it : nodecount){
            int edges = edgecount[it.first];
            int nodes = it.second;
            if(edges==(nodes*(nodes-1))/2){
                result++;
            }
        }
        return result;
    }
};
