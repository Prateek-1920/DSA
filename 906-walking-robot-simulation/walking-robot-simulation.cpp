class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        int x = 0;
        int y = 0;
        int maxdist = 0;

        unordered_set<string> obs;
        for (auto &it : obstacles) {
            obs.insert(to_string(it[0]) + "," + to_string(it[1]));
        }

        vector<vector<int>> dir = {{0,1},{1,0},{0,-1},{-1,0}}; //NESW
        int dirindex = 0;

        for(int cmd : commands){
            if(cmd==-1){
                dirindex = (dirindex+1)%4;
            }
            else if(cmd==-2){
                dirindex = (dirindex+3)%4;
            }
            else{
                for(int i=0;i<cmd;i++){
                int newx =x+dir[dirindex][0];
                int newy =y+dir[dirindex][1];
                string pos = to_string(newx) + "," + to_string(newy);
                if (obs.count(pos)) {
                    break; // hit obstacle
                }
                x = newx;
                y = newy;
                maxdist = max(maxdist,x*x+y*y);
                }
            }
        }
        return maxdist;
    }
};