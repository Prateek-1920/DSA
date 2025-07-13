class Solution {
private:
    bool checkunit(string a, string b){
        if(a.length()!=b.length())return false;
        int diff = 0;
        for(int i=0;i<a.length();i++){
            if(a[i]!=b[i]){
                diff++;
                if(diff>1)return false;
            }
        }
        return true;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        wordList.push_back(beginWord);
        int n = wordList.size();

        bool flag = false;
        for(int i=0;i<n;i++){
            if(wordList[i]==endWord){
                flag=true;
            }
        }
        if(flag==false)return 0;

        unordered_map<string,vector<string>> graph;
        unordered_set<string> visited;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(checkunit(wordList[i],wordList[j])){
                    graph[wordList[i]].push_back(wordList[j]);
                    graph[wordList[j]].push_back(wordList[i]);
                }
            }
        }

        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited.insert(beginWord);

        while(!q.empty()){
            string curr = q.front().first;
            int level = q.front().second;
            q.pop();
            for(string neighbour : graph[curr]){
                if(neighbour==endWord){
                    return level+1;
                }
                else if(visited.find(neighbour)==visited.end()){
                    visited.insert(neighbour);
                    q.push({neighbour,level+1});
                }
            }

        }
        return 0;
    }
};