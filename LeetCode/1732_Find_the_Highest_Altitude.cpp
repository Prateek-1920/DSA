class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        vector<int> altitude(n+1,0);

        altitude[1] = gain[0];
        for(int i=1;i<n;i++){
            altitude[i+1]= altitude[i] + gain[i]; 
        }

        sort(altitude.begin(),altitude.end());
        return altitude[n];

    }
};
