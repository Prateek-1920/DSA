class SnapshotArray {
public:
vector<int> arr;
vector<vector<pair<int,int>>> snap_arr;
int snapid;
    SnapshotArray(int length) {
        snapid = 0;
        snap_arr.resize(length);
        for(int i=0;i<length;i++){
            snap_arr[i].push_back({0,0});
        }
    }
    
    void set(int index, int val) {
        snap_arr[index].push_back({snapid,val});
    }
    
    int snap() {
        snapid++;
        return snapid-1;

    }
    
    int get(int index, int snap_id) {
        auto& v = snap_arr[index];
        if (v.empty()) return 0;

        auto it = upper_bound(v.begin(), v.end(), make_pair(snap_id, INT_MAX));
        it--;
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */