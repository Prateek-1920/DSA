class Solution {
private:
    bool parse(char op,vector<char>&vec){
        if(op=='!'){
            return vec[0] == 'f';
        }
    
        else if(op=='&'){
            for(auto c : vec){
                if(c=='f')return false;
            }
            return true;
        }
        else{
            for(auto c : vec){
                if(c=='t')return true;
            }
            return false;
        }
    }
   
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for(char c : expression){
            if(c==','){
                continue;
            }
            else if(c!=')'){
                st.push(c);
            }
            else{
                vector<char>temp;
                while(!st.empty() && st.top()!='('){
                    temp.push_back(st.top());
                    st.pop();
                }
                reverse(temp.begin(),temp.end());
                st.pop();
                char op = st.top();
                st.pop();
                bool b = parse(op,temp);
                st.push(b==true?'t':'f');
            }
        }
        return st.top()=='t';
    }
};