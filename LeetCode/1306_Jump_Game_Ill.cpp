class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        if(arr[start]==0)return true;
        queue<pair<int,int>> q;
        q.push({start,arr[start]});
        arr[start] = -1;

        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int idx = q.front().first;
                int val = q.front().second;
                q.pop();
                int left = idx - val;
                int right = idx + val;
                if(left>=0){
                    if(arr[left]==0){
                        return true;
                    }
                    else{
                        if(arr[left]!=-1){
                            q.push({left,arr[left]});
                            arr[left]=-1;
                        }
                    }
                }
                if(right<n){
                    if(arr[right]==0){
                        return true;
                    }
                    else{
                        if(arr[right]!=-1){
                            q.push({right,arr[right]});
                            arr[right]=-1;
                        }
                    }
                }
            }
        }
        return false;
    }
};
