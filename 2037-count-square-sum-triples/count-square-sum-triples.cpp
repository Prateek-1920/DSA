class Solution {
public:
    int countTriples(int n) {
        vector<int> vec;
        int count = 0;
        for(int i=1;i<=n;i++){
            vec.push_back(i*i);
        }

        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = vec[i] + vec[j];
                if(binary_search(vec.begin(),vec.end(),vec[i]+vec[j])){
                    if(i==j){
                        count++;
                    }
                    else{
                        count+=2;
                    }
                }
            }
        }
        return count;
    }
};