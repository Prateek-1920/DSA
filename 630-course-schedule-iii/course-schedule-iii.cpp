class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int curr_time = 0;
        priority_queue<int> pq;

        sort(courses.begin(), courses.end(), [](const auto& a, const auto& b) {
        return a[1] < b[1];
        });

        for(auto &it : courses){
            int duration = it[0];
            int last_day = it[1];
            
            if(curr_time+duration<=last_day){
                curr_time+=duration;
                pq.push(duration);
            }
            else{
                if(!pq.empty() && pq.top()>duration){
                    curr_time-=pq.top();
                    pq.pop();
                    curr_time+=duration;
                    pq.push(duration);
                }
            }
        }
        return pq.size();
    }
};