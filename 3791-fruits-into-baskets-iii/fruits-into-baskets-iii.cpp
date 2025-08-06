class Solution {
private:
    void build(int i, int l, int r, vector<int>&baskets, vector<int>& segtree){
        if(l==r){
            segtree[i] = baskets[l];
            return;
        }
        int mid = l + (r-l)/2;
        build(2*i+1,l,mid,baskets,segtree);
        build(2*i+2,mid+1,r,baskets,segtree);
        segtree[i] = max(segtree[2*i+1],segtree[2*i+2]);
    }

    bool solve(int i, int l, int r, int fruit, vector<int>& segtree){
        if(segtree[i] < fruit){
            return false;
        }
        if(l==r){
            segtree[i] = -1;
            return true;
        }
        int mid = l + (r-l)/2;
        bool placed = false;
        
        if(segtree[2*i+1] >= fruit){
            placed = solve(2*i+1,l,mid,fruit,segtree);
        }
        else{
            placed = solve(2*i+2,mid+1,r,fruit,segtree);
        }

        segtree[i] = max(segtree[2*i+1],segtree[2*i+2]);
        return placed;
    }
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segtree(4*n,-1);
        build(0,0,n-1,baskets,segtree);

        int ans = 0;
        for(int fruit : fruits){
            if(solve(0,0,n-1,fruit,segtree)==false){
                ans++;
            }
        }
        return ans;
    }
};