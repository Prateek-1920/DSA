class MyCalendar {
public:
    vector<pair<int,int>> time;
    MyCalendar() {
    }
    
    bool book(int startTime, int endTime) {
        for(auto &it : time){
            int prevstart = it.first;
            int prevend = it.second;
            if(startTime<prevend && endTime>prevstart){
                return false;
            }
        }
        time.push_back({startTime,endTime});
        return true;
    }

};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */