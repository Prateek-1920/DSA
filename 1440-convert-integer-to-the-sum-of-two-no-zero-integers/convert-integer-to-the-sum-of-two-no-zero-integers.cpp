class Solution {
private:
    bool zeros(int n){
        unordered_set<int> digits;
        while(n!=0){
            digits.insert(n%10);
            n = n/10;
        }
        if(digits.find(0)!=digits.end()){
            return false;
        }
        return true;
    }
public:
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1;i<n;i++){
            if(zeros(i)==true && zeros(n-i)==true){
                return {i,n-i};
            }
        }
        return {};
    }
};