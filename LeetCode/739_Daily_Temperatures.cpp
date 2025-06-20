class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        stack<int> st;
        vector<int> ans(n,0);
        st.push(0);

        for(int i=0;i<T.size();i++){
            while(!st.empty() && T[i]>T[st.top()]){
                int prev_idx = st.top();
                st.pop();
                ans[prev_idx] = i-prev_idx;
            }
            st.push(i);
        }
        return ans;
    }
};