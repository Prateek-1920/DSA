class Solution {
public:
    int countCollisions(string directions) {
        stack<char>st;
        int count = 0;

        for(char ch : directions){
            if(!st.empty() && st.top()=='R' && ch =='L'){
                count+=2;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top()=='R' && ch =='S'){
                count+=1;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top()=='S' && ch=='L'){
                count+=1;
                // st.pop();
                st.push('S');
            }
            else{
                st.push(ch);
            }
        }
        while(!st.empty() && st.top()=='R'){
            st.pop();
        }

        while(!st.empty()){
            if(st.top()=='R'){
                count++;
            }
            st.pop();
        }
        return count;

    }
};