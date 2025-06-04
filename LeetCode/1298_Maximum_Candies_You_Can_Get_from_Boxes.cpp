class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        queue<int> q;
        unordered_set<int> boxkeys;
        unordered_set<int> waitingbox;
        vector<bool> visited(n,false);
        int ans = 0;

        for(auto i : initialBoxes){
            q.push(i);
        }

        while(!q.empty()){
                int size = q.size();
                while(size!=0){
                    int node = q.front();
                    q.pop();
                    if(visited[node])continue;

                    if(status[node]==1 || boxkeys.find(node)!=boxkeys.end()){
                        visited[node]=true;
                        ans+=candies[node];
                        for(auto i : keys[node]){
                            if(boxkeys.find(i)==boxkeys.end()){
                                boxkeys.insert(i);
                                if(waitingbox.find(i)!=waitingbox.end()){
                                    q.push(i);
                                    waitingbox.erase(i);
                                }
                            }
                        }
                        for(auto i : containedBoxes[node]){
                            if(!visited[i]){
                                if(status[i]==1 || boxkeys.find(i)!=boxkeys.end()){
                                    q.push(i);
                                }
                                else{
                                    waitingbox.insert(i);
                                }
                            }
                        }
                    }
                    else{
                        waitingbox.insert(node);
                    }
                    size--;
            }   
        }     
        return ans;
    }
};