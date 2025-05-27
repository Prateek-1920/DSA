class Solution {
private:
    int numdig(int n){
        int digits = 0;
        while(n!=0){
            n=n/10;
            digits++;
        }
        return digits;
    }
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(auto i : nums){
            if(numdig(i)%2==0){
                count++;
            }
        }
        return count;
    }
};
