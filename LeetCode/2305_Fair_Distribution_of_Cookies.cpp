class Solution {
private:
    void backtrack(int index, vector<long long> &child, vector<int>& cookies, long long &unfairness){
        if(index==cookies.size()){
            unfairness = min(unfairness,*max_element(child.begin(),child.end()));
            return;
        }
        for(int i=0;i<child.size();i++){
            child[i]+=cookies[index];
            if(child[i]>=unfairness){
                child[i]-=cookies[index];
                continue;
            }
            backtrack(index+1,child,cookies,unfairness);
            child[i]-=cookies[index];
        }
    }
public:
    int distributeCookies(vector<int>& cookies, int k) {
        vector<long long> child(k,0);
        long long unfairness = INT_MAX;
        backtrack(0,child,cookies,unfairness);
        return unfairness;
    }
};