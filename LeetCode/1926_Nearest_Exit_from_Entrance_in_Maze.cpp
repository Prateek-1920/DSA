class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m = maze.size();
        int n = maze[0].size();

        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';

        int steps = 0 ;
        vector<pair<int,int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

        while(!q.empty()){
            int size = q.size();
            steps++;
            for(int i=0;i<size;i++){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();

                for(auto &itdir : dir){
                    int newrow = row + itdir.first;
                    int newcol = col + itdir.second;

                    if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && maze[newrow][newcol] == '.'){
                        if(newrow==0||newrow==m-1||newcol==0||newcol==n-1){
                            return steps;
                        }
                        maze[newrow][newcol] = '+';
                        q.push({newrow,newcol});
                    }
                }

            }
        }

        return -1;
    }
};
