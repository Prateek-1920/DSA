class Solution {
public:
    string triangleType(vector<int>& nums) {
        unordered_map<char,int> map;
        for(auto i : nums){
            map[i]++;
        }

        if(nums[0]+nums[1]>nums[2]){
            if(nums[1]+nums[2]>nums[0]){
                if(nums[2]+nums[0]>nums[1]){
                    if(map.size()==1){
                        return "equilateral";
                    }
                    else if(map.size()==2){
                        return "isosceles";
                    }
                    else{
                        return "scalene";
                    }
                }
            }
        }
        return "none";
    }
};
