class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<string,int> rows;
        unordered_map<string,int> cols;

        int n = grid.size();

        for(int i=0;i<n;i++){
            string num = "";
            for(int j=0;j<n;j++){
                num+=to_string(grid[i][j]);
                if(j+1!=n){
                    num+='_';
                }
            }
            rows[num]++;
        }

        for(int i=0;i<n;i++){
            string num = "";
            for(int j=0;j<n;j++){
                num+=to_string(grid[j][i]);
                if(j+1!=n){
                    num+='_';
                }
            }
            cols[num]++;
        }

        int count=0;
        for(auto &it : rows){
            if(cols.find(it.first)!=cols.end()){
                count += cols[it.first]*rows[it.first];
            }
        }
        return count;
    }
};
