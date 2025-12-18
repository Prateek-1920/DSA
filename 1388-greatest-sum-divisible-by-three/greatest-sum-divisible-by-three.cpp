class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> rem1;
        vector<int> rem2;

        for(int it : nums){
            if(it%3==1){
                rem1.push_back(it);
            }
            else if(it%3==2){
                rem2.push_back(it);
            }
        }


        sort(rem1.begin(),rem1.end());
        sort(rem2.begin(),rem2.end());

        int total_sum = accumulate(nums.begin(),nums.end(),0);
        if(total_sum%3==0){
            return total_sum;
        }
        // if(rem1.empty() || rem2.empty()){
        //     return 0;
        // }

        else if(total_sum%3==1){
            if(rem2.size()>1 && rem1.size()>0){
                total_sum = max(total_sum-rem1[0],total_sum-rem2[0]-rem2[1]);
            }
            else if(rem2.size()<2 && rem1.size()>0){
                total_sum = total_sum-rem1[0];
            }
            else if(rem1.size()<2 && rem2.size()>0){
                total_sum = total_sum-rem2[0]-rem2[1];
            }
            else{
                return total_sum;
            }
        }
        else{
            if(rem1.size()>1 && rem2.size()>0){
                total_sum = max(total_sum-rem2[0],total_sum-rem1[0]-rem1[1]);
            }
            else if(rem1.size()<2 && rem2.size()>0){
                total_sum = total_sum-rem2[0];
            }
            else if(rem2.size()<2 && rem1.size()>0){
                total_sum = total_sum-rem1[0]-rem1[1];
            }
            else{
                return total_sum;
            }
        }
        return total_sum;
    }
};