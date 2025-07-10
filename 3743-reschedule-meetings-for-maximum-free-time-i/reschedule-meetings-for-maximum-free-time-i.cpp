class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {

        // vector<pair<int, int>> events;
        int n = startTime.size();

        // for (int i = 0; i < n; i++) {
        //     events.push_back({startTime[i], endTime[i]});
        // }

        // sort(events.begin(), events.end());

        // for (int i = 0; i < n; i++) {
        //     startTime[i] = events[i].first;
        //     endTime[i] = events[i].second;
        // }


        vector<int> freetime(n+1);

        for(int i=1;i<n;i++){
            freetime[i] = startTime[i]-endTime[i-1];
        }

        freetime[0] = startTime[0];
        freetime[n] = eventTime-endTime[n-1];


        for(int i=0;i<freetime.size();i++){
            cout<<freetime[i]<<" ";
        }

        if(freetime.size()<=k+1){
            return accumulate(freetime.begin(),freetime.end(),0);
        }

        int left = 0;
        int right = 0;
        int ans = INT_MIN;
        int currsum = 0;
        while(right<freetime.size()){
            currsum+=freetime[right];
            right++;
            if(right-left==k+1){
                ans = max(ans,currsum);
                currsum-=freetime[left];
                left++;

            }
           
        }
        return ans;
    }
};