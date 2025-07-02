class Solution {
private:
    int maxscore( int i, int j, vector<int>& nums, int turn){
        if(i==nums.size() || i>j || i>nums.size() || j<0){
            return 0;
        }
        if(turn==0){
            return max(nums[i]+maxscore(i+1,j,nums,1),nums[j]+maxscore(i,j-1,nums,1));
        }
        else{
            return min(-nums[i] + maxscore(i+1,j,nums,0),-nums[j]+maxscore(i,j-1,nums,0));
        }
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int ans = maxscore(0,nums.size()-1,nums,0);
        return ans>=0;
    }
};