class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n,vector<int>(n,0));

        int top = 0;
        int bottom = n-1;
        int left = 0;
        int right = n-1;
        int num = 1;

        while(top<=bottom && left<=right){
            for(int i=left;i<=right;i++){
                mat[top][i] = num;
                num++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                mat[i][right] = num;
                num++;
            }
            right--;

            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    mat[bottom][i] = num;
                    num++;
                }
            }
            bottom--;

            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    mat[i][left]=num;
                    num++;
                }
            }
            left++;
        }
        return mat;

    }
};