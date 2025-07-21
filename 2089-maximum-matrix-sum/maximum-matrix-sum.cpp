class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long  sum = 0;
        long long neg = 0;
        long long minval = INT_MAX;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                if(matrix[i][j]<=0){
                    neg++;  
                }
                minval = min(minval,abs((long long)matrix[i][j]));
            }
        }
        if(neg%2==0){
            return sum;
        }
        else{
            return sum - 2*minval;
        }
    }
};