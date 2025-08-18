class MyHashMap {
public:
    int M = 1000;
    vector<list<pair<int,int>>> buckets;
    MyHashMap() {
        M = 1000;
        buckets.resize(M);
    }
    
    
    void put(int key, int value) {
        int bucketnum = key%M;
        auto &chain = buckets[bucketnum];

        for(auto &it : chain){
            if(it.first==key){
                it.second = value;
                return;
            }
        }
        chain.emplace_back(key,value);
    }
    
    int get(int key) {
        int bucketnum = key%M;
        auto &chain = buckets[bucketnum];

        for(auto &it : chain){
            if(it.first==key){
                return it.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int bucketnum = key%M;
        auto &chain = buckets[bucketnum];

        for(auto it = chain.begin(); it!=chain.end();it++){
            if(it->first==key){
                chain.erase(it);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */