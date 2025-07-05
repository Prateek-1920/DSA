class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {

        vector<vector<int>> ans;
        for(auto &i : firstList){
            for(auto &j : secondList){
                if(i[1]<j[0]){
                    break;
                }
                else if(i[1]>=j[0] && i[0]<=j[1]){
                    ans.push_back({max(i[0],j[0]),min(i[1],j[1])});
                }
            }
        }
        return ans;
    }
};