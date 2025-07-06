class FindSumPairs {
public:
    unordered_map<int,int>mp;
    vector<int> n1;
    vector<int> n2;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        n1=nums1;
        n2=nums2;
        for (int num : n2) {
            mp[num]++;
        }
    }
    
    void add(int index, int val) {
        mp[n2[index]]--;
        if(mp[n2[index]]==0){
            mp.erase(n2[index]);
        }
        n2[index]+=val;
        mp[n2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for(int i=0;i<n1.size();i++){
            int ele = tot-n1[i];
            if(mp.find(ele)!=mp.end()){
                ans+=mp[ele];
            }
        }
        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */