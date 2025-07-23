class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string str = x>y?"ab":"ba";
        stack<char> st;
        int score = 0;
        for(char c : s){
            if(!st.empty() && c == str[1] && st.top()==str[0]){
                st.pop();
                score+=max(x,y);
            }
            else{
                st.push(c);
            }
        }

        int i=0;
        string newstr = "";
        while(!st.empty()){
            newstr+=st.top();
            st.pop();
            i++;
        }
        reverse(newstr.begin(),newstr.end());

        str = (str=="ab")?"ba":"ab";

        for(char c : newstr){
            if(!st.empty() && c == str[1] && st.top()==str[0]){
                st.pop();
                score+=min(x,y);
            }
            else{
                st.push(c);
            }
        }
        return score;


    }
};