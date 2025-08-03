class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int left = 0;
        int n = fruits.size();
        int total = 0;
        int maxfruits = 0;

        for(int right = 0;right<n;right++){
            total += fruits[right][1];
            int steps = min(abs(startPos - fruits[left][0]), abs(startPos - fruits[right][0]))
                                    + (fruits[right][0] - fruits[left][0]);
            while(steps>k){
                total-=fruits[left][1];
                left++;
                if (left > right) break; 
                steps = min(abs(startPos - fruits[left][0]), abs(startPos - fruits[right][0]))
                        + (fruits[right][0] - fruits[left][0]);
            }
            maxfruits = max(maxfruits,total);
        }
        return maxfruits;
    }
};