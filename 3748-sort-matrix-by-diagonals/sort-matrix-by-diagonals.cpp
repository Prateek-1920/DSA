class Solution {
private:
    void sortdiag(int r, int c, vector<vector<int>>&grid, bool flag){
        int n = grid.size();
        int i = r;
        int j = c;
        vector<int>temp;

        while(i<n && j<n){
            temp.push_back(grid[i][j]);
            i++;
            j++;
        }
        if(flag==true){
            sort(temp.begin(),temp.end());
        }
        else{
            sort(temp.rbegin(),temp.rend());
        }

        i=r;
        j=c;
        for(int it : temp){
            grid[i][j]=it;
            i++;
            j++;
        }
    }
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        for(int row=0;row<n;row++){
            sortdiag(row,0,grid,false);
        }
        for(int col=1;col<n;col++){
            sortdiag(0,col,grid,true);
        }
        return grid;
    }
};