class TimeMap {
public:
    unordered_map<string,vector<pair<int,string>>> v;
    int timestamp_prev;

    TimeMap() {
        // for(int i=0;i<100;i++){
        //     v[to_string(i)].push_back({0,""});
        // }
        // timestamp_prev = 0;
    }
    
    void set(string key, string value, int timestamp) {
        v[key].push_back({timestamp,value});
        timestamp_prev = timestamp;

    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(v[key].begin(),v[key].end(),make_pair(timestamp,""),
        [](const pair<int,string>&a, const pair<int,string>&b){
            return a.first<b.first;
        });
        if (it == v[key].begin()) return "";
        return prev(it)->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */