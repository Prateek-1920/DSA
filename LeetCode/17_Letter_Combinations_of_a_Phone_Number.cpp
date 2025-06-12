class Solution {
private:
    void backtrack(int index, string& current, const string& digits, vector<string>& result){
        unordered_map<char, string> mp = {{'2', "abc"},{'3', "def"},{'4', "ghi"},{'5', "jkl"},{'6', "mno"},
        {'7', "pqrs"},{'8', "tuv"},{'9', "wxyz"}};

        if(index==digits.length()){
            result.push_back(current);
            return;
        }
        string letters = mp[digits[index]];
        for(auto i : letters){
            current+=i;
            backtrack(index+1,current,digits,result);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) return result;  
        string current = "";
        backtrack(0,current,digits,result);
        return result;

    }
};